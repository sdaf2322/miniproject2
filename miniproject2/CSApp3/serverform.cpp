#include "serverform.h"
#include "ui_serverform.h"
#include "logthread.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>
#include <QApplication>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QDebug>
#include <QMenu>
#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>

ServerForm::ServerForm(QWidget *parent) :                                             /*ServerForm 생성자*/
    QWidget(parent),
    ui(new Ui::ServerForm), totalSize(0), byteReceived(0)
{
    ui->setupUi(this);
    QList<int> sizes;
    sizes << 540 << 200;
    ui->splitter->setSizes(sizes);                                                     // messageTreeWidget과 clientTreeWidget의 크기 비율 설정

    chatServer = new QTcpServer(this);                                                 // 채팅을 위한 TCP서버 생성
    connect(chatServer, SIGNAL(newConnection( )), SLOT(clientConnect( )));             // 서버연결이 되면 clientConnect 슬롯 발생
    if (!chatServer->listen(QHostAddress::Any, PORT_NUMBER)) {
        QMessageBox::critical(this, tr("Chatting Server"), \
                              tr("Unable to start the server: %1.") \
                              .arg(chatServer->errorString( )));                       // ip주소와 포트번호를 통한 서버 연결에 실패할 경우 에러메세지 띄움
        close( );
        return;
    }

    fileServer = new QTcpServer(this);                                                 // 파일 전송을 위한 TCP서버 생성
    connect(fileServer, SIGNAL(newConnection()), SLOT(acceptConnection()));            // 서버연결이 되면 acceptConnection 슬롯 발생
    if (!fileServer->listen(QHostAddress::Any, PORT_NUMBER+1)) {
        QMessageBox::critical(this, tr("Chatting Server"), \
                              tr("Unable to start the server: %1.") \
                              .arg(fileServer->errorString( )));                       // ip주소와 포트번호를 통한 서버 연결에 실패하면 에러메세지 띄움
        close( );
        return;
    }

    qDebug("Start listening ...");

    QAction* inviteAction = new QAction(tr("&Invite"));
    inviteAction->setObjectName("Invite");
    connect(inviteAction, SIGNAL(triggered()), SLOT(inviteClient()));                   // inviteAction 누르면 inviteClient 슬롯발생

    QAction* removeAction = new QAction(tr("&Kick out"));
    connect(removeAction, SIGNAL(triggered()), SLOT(kickOut()));                        // removeAction 누르면 kickOut 슬롯발생

    menu = new QMenu;
    menu->addAction(inviteAction);
    menu->addAction(removeAction);                                                      // 각각의 액션을 메뉴에 추가
    ui->clientTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);                  // 메뉴 정책을 사용자가 정의한 것으로 함

    progressDialog = new QProgressDialog(0);                                            // 파일을 전송할 때 진행상황을 알려줄 다이얼로그
    progressDialog->setAutoClose(true);                                                 // 전송이 끝나면 자동으로 닫힘
    progressDialog->reset();                                                            // 전송이 끝나면 자동으로 리셋

    logThread = new LogThread(this);
    logThread->start();                                                                 // 스레드 시작

    connect(ui->savePushButton, SIGNAL(clicked()), logThread, SLOT(saveData()));        // save버튼 누르면 로그 저장

    qDebug() << tr("The server is running on port %1.").arg(chatServer->serverPort( ));
}

ServerForm::~ServerForm()                                                               /*ServerForm 소멸자*/
{
    delete ui;

    logThread->terminate();                                                             // 스레드 강제종료
    chatServer->close( );
    fileServer->close( );                                                               // 채팅서버와 파일 서버 닫음
}

void ServerForm::on_deletePushButton_clicked()                                          /*delete 버튼 누를 경우*/
{
    ui->messageTreeWidget->clear();                                                     // messageTreeWidget 비움
}

void ServerForm::clientConnect( )                                                       /*clientConnect 슬롯*/
{
    QTcpSocket *clientConnection = chatServer->nextPendingConnection( );                // 소켓 생성
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(receiveData( )));              // 소켓에서 읽을 준비가 되면 reciveData 슬롯 발생
    connect(clientConnection, SIGNAL(disconnected( )), SLOT(removeClient()));           // 연결이 끊어지면 removeClient 슬롯 발생
    qDebug("new connection is established...");
}

void ServerForm::receiveData( )                                                         /*receiveData 슬롯*/
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    QByteArray bytearray = clientConnection->read(BLOCK_SIZE);                          // 소켓으로 부터 데이터 받음

    Chat_Status type;
    char data[1020];
    memset(data, 0, 1020);                                                              // 타입과 받을 데이터에 대한 정보를 0으로 초기화

    QDataStream in(&bytearray, QIODevice::ReadOnly);                                    // 읽기 전용으로 설정
    in.device()->seek(0);                                                               // 읽기 위해 처음 위치로 감
    in >> type;
    in.readRawData(data, 1020);                                                         // 소켓으로 전송받은 타입과 데이터를 저장 후 읽음

    QString ip = clientConnection->peerAddress().toString();
    quint16 port = clientConnection->peerPort();
    QString name = QString::fromStdString(data);                                        // ip주소, 포트번호, 전송받은 데이터를 저장

    qDebug() << ip << " : " << type;

    switch(type) {
    case Chat_Login:                                                                                    /*타입이 chat_login이면*/
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchFixedString, 1)) {
            if(item->text(0) != "-") {
                item->setText(0, "-");
            }                                                                                           // 전송받은 데이터(이름)과 일치하는 항목을 찾아 x표시를 -로 바꿈
            clientSocketHash[name] = clientConnection;                                                  // 소켓을 해쉬에 저장
        }
        break;
    case Chat_In:                                                                                       /*타입이 chat_in이면*/
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchFixedString, 1)) {
            if(item->text(0) != "O") {
                item->setText(0, "O");
            }                                                                                           // 전송받은 데이터(이름)과 일치하는 항목 찾아 -를 o로 바꿈
            clientNameHash[port] = name;                                                                // 네임해쉬에 이름 저장
            if(clientSocketHash.contains(name))
                clientSocketHash[name] = clientConnection;                                              // 소켓해쉬에 이름이 있다면 소켓을 소켓해쉬에 저장
        }
        break;
    case Chat_Talk: {                                                                                   /*타입이 Chat_Talk이면*/
        foreach(QTcpSocket *sock, clientSocketHash.values()) {
            qDebug() << sock->peerPort();
            if(clientNameHash.contains(sock->peerPort()) && port != sock->peerPort()) {
                QByteArray sendArray;
                sendArray.clear();
                QDataStream out(&sendArray, QIODevice::WriteOnly);                                      // 쓰기모드로 설정
                out << Chat_Talk;                                                                       // 타입 저장
                sendArray.append("<font color=lightsteelblue>");                                        // 폰트 설정
                sendArray.append(clientNameHash[port].toStdString().data());                            // sendArray에 이름 추가
                sendArray.append("</font> : ");
                sendArray.append(name.toStdString().data());                                            // sendArray에 채팅 메세지 추가
                sock->write(sendArray);                                                                 // 소켓으로 보냄
                qDebug() << sock->peerPort();
            }
        }

        QTreeWidgetItem* item = new QTreeWidgetItem(ui->messageTreeWidget);
        item->setText(0, ip);
        item->setText(1, QString::number(port));
        item->setText(2, QString::number(clientIDHash[clientNameHash[port]]));
        item->setText(3, clientNameHash[port]);
        item->setText(4, QString(data));
        item->setText(5, QDateTime::currentDateTime().toString());
        item->setToolTip(4, QString(data));
        ui->messageTreeWidget->addTopLevelItem(item);                       // ip, 포트번호, 고객ID, 이름, 메세지 현재 시간에 대한 정보를 messageTreeWidget의 탑레벨로 옮김

        for(int i = 0; i < ui->messageTreeWidget->columnCount(); i++)
            ui->messageTreeWidget->resizeColumnToContents(i);                                              // 내용에 따른 열 맞춤

        logThread->appendData(item);                                                                       // 로그 정보를 스레드의 appendData에 삽입
    }
        break;
    case Chat_Out:                                                                                          /*타입이 Chat_Out이면*/
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {                   // 이름과 일치하는 항목 찾음
            if(item->text(0) != "-") {
                item->setText(0, "-");                                                                      // o를 -로 바꿈
            }
            clientNameHash.remove(port);                                                                    // 포트에 해당하는 이름 제거
        }
        break;
    case Chat_LogOut:                                                                                       /*타입이 Chat_LogOut이면*/
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {                   // 이름과 일치하는 항목 찾음
            if(item->text(0) != "X") {
                item->setText(0, "X");                                                                      // -에서 x로 바꿈
            }
            clientSocketHash.remove(name);                                                                  // 소켓해쉬에서 이름 제거
        }
        break;
    }
}

void ServerForm::removeClient()                                                                             /*removeClient 슬롯*/
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    if(clientConnection != nullptr) {
        QString name = clientNameHash[clientConnection->peerPort()];                                        // 포트번호에 해당하는 이름
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {
            item->setText(0, "X");                                                                          // 이름과 일치하는 항목 찾아서 x로 표시
        }
        clientSocketHash.remove(name);                                                                      // 소켓 해쉬에서 이름에 해당하는 소켓 제거
        clientConnection->deleteLater();                                                                    // 소켓 제거
    }
}

void ServerForm::addClient(int id, QString name)                                                            /*addClient 슬롯*/
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->clientTreeWidget);
    item->setText(0, "X");
    item->setText(1, name);                                                                                 // clientTreeWidget에 x표시와 이름 표시
    ui->clientTreeWidget->addTopLevelItem(item);                                                            // 탑레벨로 옮김
    clientIDHash[name] = id;                                                                                // 해쉬에 이름에 이름을 키로 아이디 저장
    ui->clientTreeWidget->resizeColumnToContents(0);                                                        // 내용에 따른 열 크기 조절
}

void ServerForm::on_clientTreeWidget_customContextMenuRequested(const QPoint &pos)                          /*마우스 우측키 누를 경우*/
{
    foreach(QAction *action, menu->actions()) {
        if(action->objectName() == "Invite")
            action->setEnabled(ui->clientTreeWidget->currentItem()->text(0) != "O");                        // o표시가 아닐 때 초대 액션 활성화
        else                                        // 강퇴
            action->setEnabled(ui->clientTreeWidget->currentItem()->text(0) == "O");                        // 그렇지 않으면 강퇴 액션 활성화
    }
    QPoint globalPos = ui->clientTreeWidget->mapToGlobal(pos);                                              // 전역좌표로 설정
    menu->exec(globalPos);                                                                                  // 마우스 커서에 메뉴창 띄움
}

/* 클라이언트 강퇴하기 */
void ServerForm::kickOut()                                                                                  /*kickout 슬롯*/
{
    QByteArray sendArray;
    QDataStream out(&sendArray, QIODevice::WriteOnly);                                                      // 쓰기모드로 설정
    out << Chat_KickOut;
    out.writeRawData("", 1020);                                                                             // 타입과 데이터를 씀

    QString name = ui->clientTreeWidget->currentItem()->text(1);
    QTcpSocket* sock = clientSocketHash[name];                                                              // 이름에 해당하는 소켓 정의
    sock->write(sendArray);                                                                                 // 소켓으로 데이터 보냄

    ui->clientTreeWidget->currentItem()->setText(0, "-");                                                   // O에서 -로 표시
}

/* 클라이언트 초대하기 */
void ServerForm::inviteClient()                                                                             /*inviteClient 슬롯*/
{
    QByteArray sendArray;
    QDataStream out(&sendArray, QIODevice::WriteOnly);
    out << Chat_Invite;
    out.writeRawData("", 1020);                                                                             // 타입과 데이터를 씀


    QString name = ui->clientTreeWidget->currentItem()->text(1);
    QTcpSocket* sock = clientSocketHash[name];                                                              // 이름에 해당하는 소켓 정의
    sock->write(sendArray);                                                                                 // 소켓으로 데이터 보냄

    ui->clientTreeWidget->currentItem()->setText(0, "O");                                                   // -에서 o로 바꿈
}

/* 파일 전송을 위한 소켓 생성 */
void ServerForm::acceptConnection()                                                                         /*acceptConnection 슬롯*/
{
    qDebug("Connected, preparing to receive files!");

    QTcpSocket* receivedSocket = fileServer->nextPendingConnection();
    connect(receivedSocket, SIGNAL(readyRead()), this, SLOT(readClient()));                                 // 소켓에서 읽을 준비가 되면 readClient 슬롯 발생
}

/* 파일 전송 */
void ServerForm::readClient()                                                                               /*readClient 슬롯*/
{
    qDebug("Receiving file ...");
    QTcpSocket* receivedSocket = dynamic_cast<QTcpSocket *>(sender( ));
    QString filename, name;

    if (byteReceived == 0) {                                                                                // 받은 데이터 크기가 0이면
        progressDialog->reset();                                                                            // 리셋하고 띄움
        progressDialog->show();                                                                             // progress 다이얼로그 띄움

        QString ip = receivedSocket->peerAddress().toString();
        quint16 port = receivedSocket->peerPort();
        qDebug() << ip << " : " << port;

        QDataStream in(receivedSocket);
        in >> totalSize >> byteReceived >> filename >> name;                                                // 파일 전체크기, 받은 데이터, 파일명, 이름 입력
        progressDialog->setMaximum(totalSize);                                                              // 다이얼로그 전체 크기 파일 전체 크기로 설정

        QTreeWidgetItem* item = new QTreeWidgetItem(ui->messageTreeWidget);
        item->setText(0, ip);
        item->setText(1, QString::number(port));
        item->setText(2, QString::number(clientIDHash[name]));
        item->setText(3, name);
        item->setText(4, filename);
        item->setText(5, QDateTime::currentDateTime().toString());
        item->setToolTip(4, filename);                                                                     // ip, 포트번호, 고객id, 이름, 파일명, 시간을 씀

        /* 컨텐츠의 길이로 QTreeWidget의 헤더의 크기를 고정 */
        for(int i = 0; i < ui->messageTreeWidget->columnCount(); i++)
            ui->messageTreeWidget->resizeColumnToContents(i);                                              // 내용에 따른 열 크기 설정

        ui->messageTreeWidget->addTopLevelItem(item);                                                      // 탑레벨로 옮김
        logThread->appendData(item);                                                                 // 스레드의 appendData에 ip, 포트번호, 고객id, 이름, 파일명, 시간 삽입

        QFileInfo info(filename);
        QString currentFileName = info.fileName();
        file = new QFile(currentFileName);
        file->open(QFile::WriteOnly);                                                                     // 파일을 쓰기모드로 오픈
    } else {                                                                                              // 데이터를 받고 있다면
        inBlock = receivedSocket->readAll();

        byteReceived += inBlock.size();                                                                 // 받은 데이터 전체 크기에 파싱해서 받은 데이터의 크기를 더함
        file->write(inBlock);                                                                           // 받은 파일 소켓으로 보냄
        file->flush();
    }

    progressDialog->setValue(byteReceived);

    if (byteReceived == totalSize) {                                                                      // 파일 다 읽으면
        qDebug() << QString("%1 receive completed").arg(filename);

        inBlock.clear();
        byteReceived = 0;                                                                                 // 받은 데이터 초기화
        totalSize = 0;                                                                                    // 전체 크기 초기화
        progressDialog->reset();                                                                          // 다이얼로그 리셋
        progressDialog->hide();                                                                           // 다이얼로그 숨김

        file->close();
        delete file;                                                                                      // 파일객체 삭제
    }
}
