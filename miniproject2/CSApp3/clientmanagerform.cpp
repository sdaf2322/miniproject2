#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "clientitem.h"

#include <QFile>
#include <QMenu>

ClientManagerForm::ClientManagerForm(QWidget *parent) :                             /*ClientManagerForm 생성자*/
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);
    ui->idLineEdit->setDisabled(true);                                              // idLineEidt 칸을 읽기전용으로 만듦
    ui->phoneNumberLineEdit->setInputMask("000-0000-0000");                         // 전화번호를 입력하는 LineEidt에 마스크 적용

    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);                                                  // 화면에서 tab위젯과 tree위젯의 크기 비율을 설정

    QAction* removeAction = new QAction(tr("&Remove"));
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));                 // removeAction을 누르면 removeItem 슬롯을 발생

    menu = new QMenu;
    menu->addAction(removeAction);                                                  // 메뉴 만들어서 removeAction을 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));   // 트리위젯에서 오른쪽 마우스 키 누르면 팝업창 뜸

    // searchLineEdit에서 엔터키를 눌렀을 경우 on_searchPushButton_clicked() 슬롯을 발생
    connect(ui->searchLineEdit, SIGNAL(returnPressed()), SLOT(on_searchPushButton_clicked()));

}

void ClientManagerForm::LoadData()                                                  /*텍스트 파일에 저장된 내용 불러오기*/
{
    QFile file("clientlist10.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;                                                                     // 파일이 읽기전용이나 텍스트 파일이 아니면 리턴

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");                                      // 텍스트 파일에 저장된 내용을 ',' 단위로 끊어서 리스트에 저장
        if(row.size() > 3) {
            int id = row[0].toInt();
            ClientItem* c = new ClientItem(id, row[1], row[2], row[3]);
            ui->treeWidget->addTopLevelItem(c);              // 텍스트 파일에 저장된 id, 이름, 전화번호, 주소에 대한 내용을 불러와 생성자를 정의한 뒤 tree위젯의 탑레벨로 옮김
            clientList.insert(id, c);                                               // clientList에 생성자를 넣음
            emit clientAdded(id, row[1]);                                           // clientAdded 시그널 방출
        }
    }
    file.close( );                                                                  // 파일 닫기
}


ClientManagerForm::~ClientManagerForm()                                             /*텍스트 id, 이름, 전화번호, 주소에 대한 내용을 저장*/
{
    delete ui;

    QFile file("clientlist10.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;                                                                     // 파일이 읽기전용이나 텍스트 파일이 아니면 리턴

    QTextStream out(&file);
    for (const auto& v : clientList.values()) {
        ClientItem* c = v;
        out << c->getID() << ", " << c->getName() << ", ";
        out << c->getPhoneNumber() << ", ";
        out << c->getAddress() << "\n";
    }                                                                               // 텍스트 파일에 id, 이름, 전화번호, 주소에 대한 내용 저장
    file.close( );                                                                  // 파일 닫기
}

int ClientManagerForm::makeId( )                                                    /*id 자동생성*/
{
    if(clientList.size( ) == 0) {
        return 100;                                                                 // clientList에 아무런 내용이 없으면 100부터 시작
    } else {
        auto id = clientList.lastKey();
        return ++id;                                                                // 그렇지 않다면 clientList에서 마지막 키 값을 가져와 1을 더하고 리턴
    }
}

void ClientManagerForm::removeItem()                                                /*removeItem 슬롯*/
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();                          // 트리위젯에서 현재 아이템 가져옴
    if(item != nullptr) {
        clientList.remove(item->text(0).toInt());                                   // 해당 id의 ClientItem 삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();                                                   // 갱신된 정보를 탑레벨로 옮김
        ui->idLineEdit->clear();                                                    // idLineEdit 칸 지움
    }
}

void ClientManagerForm::showContextMenu(const QPoint &pos)                          /*showContextMenu 슬롯*/
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);                            // 전역좌표로 만들어서 가져옴
    menu->exec(globalPos);                                                          // 마우스 커서 좌표에서 메뉴창을 띄움
}

void ClientManagerForm::on_searchPushButton_clicked()                               /*search 버튼을 눌렀을 경우*/
{
    ui->searchTreeWidget->clear();                                                  // searchTreeWidget 창 비우기

    int i = ui->searchComboBox->currentIndex();                                     // sarchComboBox의 인덱스 값 가져옴

    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains                       // 플래그로 대소문자를 구분해서 글자를 비교하는 역할
                   : Qt::MatchCaseSensitive;

    auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);    // 트리위젯에서 searchLineEdit에서 입력한 글자와 같은 항목들을 가져옴

    foreach(auto i, items)
    {
        ClientItem* c = static_cast<ClientItem*>(i);
        int id = c->getID();
        QString name = c->getName();
        QString number = c->getPhoneNumber();
        QString address = c->getAddress();
        ClientItem* item = new ClientItem(id, name, number, address);               // 항목에서 가져온 id, 이름, 전화번호, 주소에 대한 정보를 ClientItem에 정의
        ui->searchTreeWidget->addTopLevelItem(item);                                // id, 이름, 전화번호, 주소가 담긴 ClientItem을 searchTreeWidget의 탑레벨로 옮김
    }
}

void ClientManagerForm::on_modifyPushButton_clicked()                               /*Modify 버튼을 눌렀을 경우*/
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();                          // treeWidget에서 현재 선택된 항목 가져옴
    if(item != nullptr) {
        int key = item->text(0).toInt();
        ClientItem* c = clientList[key];                                            // clientList에서 키 값과 일치ㅏ는 ClientItem 가져옴
        QString name, number, address;
        name = ui->nameLineEdit->text();
        number = ui->phoneNumberLineEdit->text();
        address = ui->addressLineEdit->text();                                      // 이름, 전화번호, 주소에 대한 정보를 LineEidt에 적힌 글자로 수정
        c->setName(name);
        c->setPhoneNumber(number);
        c->setAddress(address);                                                     // 수정된 이름, 전화번호, 주소에 대한 정보로 ClientItem을 재정의
        clientList[key] = c;                                                        // clientList에 수정한 ClientItem 저장
    }
}

void ClientManagerForm::on_addPushButton_clicked()                                  /*Add 버튼 눌렀을 경우 */
{
    QString name, number, address;
    int id = makeId( );                                                             // 아이디 자동생성
    name = ui->nameLineEdit->text();
    number = ui->phoneNumberLineEdit->text();
    address = ui->addressLineEdit->text();                                          // LineEidt에 쓴 이름, 전화번호, 주소에 대한 정보를 각각의 변수에 저장
    if(name.length()) {
        ClientItem* c = new ClientItem(id, name, number, address);                  // LineEidt에 쓴 이름, 전화번호, 주소에 대한 정보로 ClientItem 재정의
        clientList.insert(id, c);                                                   // clientList에 아이디에 해당하는 값 삽입
        ui->treeWidget->addTopLevelItem(c);                                         // ClientItem을 treeWidget의 탑레벨로 옮김
        emit clientAdded(id, name);                                                 // clientAdded 시그널 방출
    }
}

void ClientManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)    /*treeWidget에서 항목을 클릭했을 경우*/
{
    Q_UNUSED(column);
    ui->idLineEdit->setText(item->text(0));
    ui->nameLineEdit->setText(item->text(1));
    ui->phoneNumberLineEdit->setText(item->text(2));
    ui->addressLineEdit->setText(item->text(3));                                        // 각각의 LineEidt에 클릭한 항목의 id, 이름, 전화번호, 주소를 씀
}

ClientItem* ClientManagerForm::search(int id)                                           /*search함수*/
{
    auto it = clientList.find(id);                                                      // clientList에서 id(키)에 해당하는 ClientItem 불러옴
    return (it != clientList.end() ? clientList[id] : nullptr);                         // clientList가 끝이 아니면 키에 해당하는 ClientItem을 반환, 그렇지 않으면 nullptr
}

const QMap<int, ClientItem*>& ClientManagerForm::getList()                              /*getList 함수*/
{
    return clientList;                                                                  // clientList를 읽기전용으로 해서 불러옴
}
