#include "chattingform.h"
#include "ui_chattingform.h"

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDataStream>
#include <QTcpSocket>
#include <QApplication>
#include <QThread>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>

#define BLOCK_SIZE      1024

ChattingForm::ChattingForm(QWidget *parent)                                                /*chattingForm 생성자*/
    : QWidget(parent), isSent(false),
    ui(new Ui::ChattingForm){
    ui->setupUi(this);

    QSettings settings("ChatClient", "Chat Client");
    ui->name->setText(settings.value("ChatClient/ID").toString());

    ui->serverAddress->setText("127.0.0.1");                                                // ip 주소
    ui->serverAddress->setPlaceholderText("Input IP Number");                               // serverAddress에 내용이 없으면 해당 텍스트 출력
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");                       // 정규 표현식
    QRegularExpressionValidator validator(re);                                              // 정규 표현식이 맞는지 검사
    ui->serverAddress->setPlaceholderText("Server IP Address");                             // nameLineEidt에 내용이 없으면 해당 텍스트 출력
    ui->serverAddress->setValidator(&validator);

    ui->serverPort->setText(QString::number(PORT_NUMBER));                                  // 포트 번호 씀
    ui->serverPort->setInputMask("00000;_");                                                // 마스크 설정
    ui->serverPort->setPlaceholderText("Server Port No");                                   // serverPort에 아무런 내용이 없으면 해당 텍스트 출력

    ui->message->setReadOnly(true);                                                         // 메세지 창은 읽기전용으로만 설정

    ui->inputLine->setPlaceholderText("Input Chatting");                                    // 입력 칸에 아무런 글자가 없으면 해당 텍스트 출력
    connect(ui->inputLine, SIGNAL(returnPressed( )), SLOT(sendData( )));                        // 엔터 누르면 sendData 슬롯
    connect(ui->inputLine, SIGNAL(returnPressed( )), ui->inputLine, SLOT(clear( )));            // 엔터 누르면 inputLine 비움
    connect(ui->sentButton, SIGNAL(clicked( )), SLOT(sendData( )));                             // send 버튼 누르면 sendData 슬롯 발생
    connect(ui->sentButton, SIGNAL(clicked( )), ui->inputLine, SLOT(clear( )));                 // send 버튼 누르면 inputLine 비움
    ui->inputLine->setDisabled(true);                                                           // inputLine 비활성화
    ui->sentButton->setDisabled(true);                                                          // send 버튼 비활성화

    connect(ui->connectButton, SIGNAL(clicked()), SLOT(connectButton_clicked()));               // connect 버튼 누르면 connectButton_clicked 슬롯 발생

    connect(ui->fileButton, SIGNAL(clicked( )), SLOT(sendFile( )));                             // 파일 버튼 누르면 sendFile 슬롯 발생
    ui->fileButton->setDisabled(true);                                                          // 파일 버튼 비활성화

    connect(ui->quitButton, SIGNAL(clicked( )), qApp, SLOT(quit( )));                           // 종료 버튼 누르면 종료

    clientSocket = new QTcpSocket(this);
    connect(clientSocket, &QAbstractSocket::errorOccurred,
            [=]{ qDebug( ) << clientSocket->errorString( ); });                                     // 에러 발생 시 에러메세지
    connect(clientSocket, SIGNAL(readyRead( )), SLOT(receiveData( )));                              // 읽을 준비가 되면 리시브 데이터 슬롯
    connect(clientSocket, SIGNAL(disconnected( )), SLOT(disconnect( )));                            // 연결 종료시 디스커넥트 슬롯

    /* 파일 전송을 위한 소켓 */
    fileClient = new QTcpSocket(this);
    connect(fileClient, SIGNAL(bytesWritten(qint64)), SLOT(goOnSend(qint64)));                      // 시그널 발생시 goOnSend 슬롯 발생

    progressDialog = new QProgressDialog(0);                                                        // 다이얼로그 생성
    progressDialog->setAutoClose(true);                                                             // 파일을 다 보내면 자동 종료
    progressDialog->reset();                                                                        // 파일을 다 보내면 리셋

    setWindowTitle(tr("Chat Client"));
}

ChattingForm::~ChattingForm( )                                                                     /*ChattingForm 소멸자*/
{
    clientSocket->close( );                                                                        // 소켓 닫음
    QSettings settings("ChatClient", "Chat Client");
    settings.setValue("ChatClient/ID", ui->name->text());
}

/* 창이 닫힐 때 서버에 연결 접속 메시지를 보내고 종료 */
void ChattingForm::closeEvent(QCloseEvent*)                                                         /*closeEvent 이벤트*/
{
    sendProtocol(Chat_LogOut, ui->name->text().toStdString().data());                               // 타입과 이름 전송
    clientSocket->disconnectFromHost();                                                             // 소켓 연결 종료
    if(clientSocket->state() != QAbstractSocket::UnconnectedState)
        clientSocket->waitForDisconnected();                                                        // 소켓의 연결이 끊기지 않으면 기다림
}

void ChattingForm::connectButton_clicked()                                                          /*connectButton_clicked 슬롯*/
{
    if(ui->connectButton->text() == tr("Log In")) {                                                 // 타입이 log in이면
        clientSocket->connectToHost(ui->serverAddress->text( ),
                                    ui->serverPort->text( ).toInt( ));                              // 소켓 연결
        clientSocket->waitForConnected();
        sendProtocol(Chat_Login, ui->name->text().toStdString().data());                            // 타입과 이름 전송
        ui->connectButton->setText(tr("Chat in"));                                                  // 버튼을 chat in으로 바꿈
        ui->name->setReadOnly(true);
    } else if(ui->connectButton->text() == tr("Chat in"))  {                                        // 타입이 chat in이면
        sendProtocol(Chat_In, ui->name->text().toStdString().data());                               // 타입과 이름 전송
        ui->connectButton->setText(tr("Chat Out"));                                                 // 버튼을 chat out으로 바꿈
        ui->inputLine->setEnabled(true);
        ui->sentButton->setEnabled(true);
        ui->fileButton->setEnabled(true);                                                           // 버튼 활성화
    } else if(ui->connectButton->text() == tr("Chat Out"))  {                                       // 타입이 chat out이면
        sendProtocol(Chat_Out, ui->name->text().toStdString().data());                              // 타입과 이름 전송
        ui->connectButton->setText(tr("Chat in"));
        ui->inputLine->setDisabled(true);
        ui->sentButton->setDisabled(true);
        ui->fileButton->setDisabled(true);                                                          // 버튼 비활성화
    }
}

/* 데이터를 받을 때 */
void ChattingForm::receiveData( )                                                                   // receiveData 슬롯
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender( ));
    if (clientSocket->bytesAvailable( ) > BLOCK_SIZE) return;
    QByteArray bytearray = clientSocket->read(BLOCK_SIZE);

    Chat_Status type;
    char data[1020];
    memset(data, 0, 1020);                                                                          // 받을 데이터의 내용을 0으로 초기화

    QDataStream in(&bytearray, QIODevice::ReadOnly);                                                // 읽기 전용으로 설정
    in.device()->seek(0);                                                                           // 읽기 위해 처음위치로 감
    in >> type;
    in.readRawData(data, 1020);                                                                     // 타입과 데이터를 읽음

    switch(type) {
    case Chat_Talk:                                                                                 /*타입이 Chat_Talk이면*/
        ui->message->append(QString(data));
        ui->inputLine->setEnabled(true);
        ui->sentButton->setEnabled(true);
        ui->fileButton->setEnabled(true);                                                           // 버튼 활성화
        break;
    case Chat_KickOut:                                                                              /*타입이 Chat_KickOut이면*/
        QMessageBox::critical(this, tr("Chatting Client"), \
                              tr("Kick out from Server"));                                          // 경고메세지 띄움
        ui->inputLine->setDisabled(true);
        ui->sentButton->setDisabled(true);
        ui->fileButton->setDisabled(true);                                                          // 버튼 비활성화
        ui->name->setReadOnly(false);                                                               // 메시지 입력 불가
        break;
    case Chat_Invite:                                                                               /*타입이 Chat_Invite이면*/
        QMessageBox::critical(this, tr("Chatting Client"), \
                              tr("Invited from Server"));                                           // 경고메세지 띄움
        ui->inputLine->setEnabled(true);
        ui->sentButton->setEnabled(true);
        ui->fileButton->setEnabled(true);                                                           // 버튼 활성화
        ui->name->setReadOnly(true);                                                                // 메시지 입력 가능
        break;
    };
}

/* 연결이 끊어졌을 때 : 상태 변경 */
void ChattingForm::disconnect( )                                                                    /*disconnect 슬롯*/
{
    QMessageBox::critical(this, tr("Chatting Client"), \
                          tr("Disconnect from Server"));                                            // 경고메세지 띄움
    ui->inputLine->setEnabled(false);                                                               // 버튼 활성화
    ui->name->setReadOnly(false);                                                                   // 읽기전용으로 설정
    ui->sentButton->setEnabled(false);                                                              // 버튼 활성화
    ui->connectButton->setText(tr("Log in"));                                                       // 버튼 log in으로 바꿈
}

/* 프로토콜을 생성해서 서버로 전송 */
void ChattingForm::sendProtocol(Chat_Status type, char* data, int size)                             /*sendProtocol 함수*/
{
    QByteArray dataArray;
    QDataStream out(&dataArray, QIODevice::WriteOnly);                                              // 쓰기모드로 설정
    out.device()->seek(0);                                                                          // 처음 위치로 감
    out << type;
    out.writeRawData(data, size);                                                                   // 타입과 데이터 씀
    clientSocket->write(dataArray);                                                                 // 서버로 전송
    clientSocket->flush();
    while(clientSocket->waitForBytesWritten());
}

/* 메시지 보내기 */
void ChattingForm::sendData()                                                                       /*sendData 슬롯*/
{
    QString str = ui->inputLine->text();
    if(str.length()) {
        QByteArray bytearray;                                                                       // 인풋라인의 메세지가 들어가 있음
        bytearray = str.toUtf8( );
        ui->message->append("<font color=red>나</font> : " + str);                                   //화면에 표시 : 앞에 '나'라고 추가
        sendProtocol(Chat_Talk, bytearray.data());                                                   // 서버로 전송
    }
}

/* 파일 전송시 여러번 나눠서 전송 */
void ChattingForm::goOnSend(qint64 numBytes)                                                       /*goOnSend 슬롯*/
{
    byteToWrite -= numBytes;                                                                        // 남은 데이터에서 파싱한 데이터 뺌
    outBlock = file->read(qMin(byteToWrite, numBytes));                                             // 파싱한 파일
    fileClient->write(outBlock);                                                                    // 파싱한 파일 서버로 보냄

    progressDialog->setMaximum(totalSize);                                                          // 다이얼로그 전체 크기를 파일 크기로 설정
    progressDialog->setValue(totalSize-byteToWrite);                                                // 현재 진행 상황을 전체 크기에서 남은 데이터 수를 뺀 값으로 설정

    if (byteToWrite == 0) {                                                                         // 파일 다 보내면
        qDebug("File sending completed!");
        progressDialog->reset();                                                                    // 리셋
    }
}

/* 파일 보내기 */
void ChattingForm::sendFile()                                                                       /*sendFile 슬롯*/
{
    loadSize = 0;
    byteToWrite = 0;
    totalSize = 0;
    outBlock.clear();

    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.length()) {
        file = new QFile(filename);
        file->open(QFile::ReadOnly);                                                                // 파일 오픈

        qDebug() << QString("file %1 is opened").arg(filename);
        progressDialog->setValue(0);                                                                // 다이얼로그 현재 진행 상황

        if (!isSent) {
            fileClient->connectToHost(ui->serverAddress->text( ),
                                      ui->serverPort->text( ).toInt( ) + 1);
            isSent = true;
        }                                                                                           // 파일을 처음 보내는 거면 서버와 연결하고 isSent를 true로 바꿈

        byteToWrite = totalSize = file->size();                                                     // 남은 파일 데이터 크기
        loadSize = 1024;                                                                            // 파싱해서 보낼 데이터 크기

        QDataStream out(&outBlock, QIODevice::WriteOnly);
        out << qint64(0) << qint64(0) << filename << ui->name->text();                              // 전체 파일 크기, 파싱해서 보낼 크기, 파일명, 보낸사람

        totalSize += outBlock.size();                                                               // 전체 파일 크기 설정
        byteToWrite += outBlock.size();                                                             // 남은 파일 크기 설정

        out.device()->seek(0);                                                                      // 처음 위치로 감
        out << totalSize << qint64(outBlock.size());                                                // 전체 파일 크기와 파싱해서 보낼 크기

        fileClient->write(outBlock);                                                                // 서버로 보냄

        progressDialog->setMaximum(totalSize);                                                      // 다이얼로그 전체 크기 설정
        progressDialog->setValue(totalSize-byteToWrite);                                            // 다이얼로그 현재 진행 상황 설정
        progressDialog->show();                                                                     // 다이얼로그 띄움
    }
    qDebug() << QString("Sending file %1").arg(filename);
}
