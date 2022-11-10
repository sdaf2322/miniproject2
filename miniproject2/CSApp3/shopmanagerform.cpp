#include "shopmanagerform.h"
#include "ui_shopmanagerform.h"
#include "shopitem.h"

#include <QFile>
#include <QMenu>


ShopManagerForm::ShopManagerForm(QWidget *parent, ClientManagerForm* cm, ProductManagerForm* pm) :
    QWidget(parent), cm(cm), pm(pm),                                            /*ShopManagerForm 생성자*/
    ui(new Ui::ShopManagerForm)
{
    ui->setupUi(this);
    ui->idLineEdit->setDisabled(true);                                          // idLineEdit을 읽기전용으로 설정
    ui->productIDLineEdit->setDisabled(true);                                   // productIDLineEdit을 읽기전용으로 설정
    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);                                              // tree위젯과 tab위젯의 크기 비율 설정

    QAction* removeAction = new QAction(tr("&Remove"));                         // removeAction 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));             // removeAction 누르면 removeItem 슬롯 발생

    menu = new QMenu;
    menu->addAction(removeAction);                                              // 메뉴 만들어서 removeAction 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);                // 사용자가 정의한 메뉴를 정책으로 함

    // 트리위젯에서 오른쪽 마우스 키 누르면 showContextMenu 슬롯 발생
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), SLOT(showContextMenu(QPoint)));

    // searchLineEdit에서 엔터키를 눌렀을 경우 on_searchPushButton_clicked() 슬롯 발생
    connect(ui->searchLineEdit, SIGNAL(returnPressed()), SLOT(on_searchPushButton_clicked()));

    ui->shopDateEdit->setDate(QDate::currentDate());                            // 날짜 다이얼로그에서 오늘 날짜로 표시
    ui->shopDateEdit->setMinimumDate(QDate(1900, 1, 1));                        // 입력할 수 있는 날짜의 최소 기준
    ui->shopDateEdit->setMaximumDate(QDate(2100, 12, 31));                      // 입력할 수 있는 날짜의 최대 기준
}

void ShopManagerForm::LoadData()                                                /*텍스트 파일에서 id, 고객명, 제품명, 가격, 고객id, 제품id, 구매일, 수량, 옵션 정보 불러옴*/
{
    QFile file("shoplist10.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;                                                                 // 파일이 읽기전용이나 텍스트 파일이 아니면 리턴

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");         // 텍스트 파일에서 id, 고객명, 제품명, 가격, 고객id, 제품id, 구매일, 수량, 옵션 정보를 ','단위로 불러와 리스트에 저장
        if(row.size()) {
            int id = row[0].toInt();
            QString cname = cm->getList().find(row[1].toInt()).value()->getName();
            QString pname = pm->getList().find(row[2].toInt()).value()->getProductName();
            QString price = pm->getList().find(row[2].toInt()).value()->getPrice();

            // 불러온 각각의 정보들로 ShopItem 정의
            ShopItem* s = new ShopItem(id, row[1].toInt(), cname, row[2].toInt(), pname, row[5], row[4], row[3], price);

            ui->treeWidget->addTopLevelItem(s);                                // ShopItem을 tree위젯의 탑레벨로 옮김

            shopList.insert(id, s);                                            // ShopItem을 shopList에 삽입
        }
    }
    file.close( );                                                             // 파일 닫기
}

ShopManagerForm::~ShopManagerForm()                                            /*텍스트 파일에 id, 고객명, 제품명, 가격, 고객id, 제품id, 구매일, 수량, 옵션에 대한 정보를 저장*/
{
    delete ui;

    QFile file("shoplist10.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;                                                                // 파일이 쓰기전용이나 텍스트 파일이 아니면 리턴

    QTextStream out(&file);
    for (const auto& v : shopList.values()) {                                  // shopList에서 ShopItem들을 가져옴
        ShopItem* s = v;
        out << s->id() << ", " ;
        out << s->getClientID() << ", ";
        out << s->getProductID() << ", ";
        out << s->getOption() << ", ";
        out << s->getQuantity() << ", ";       
        out << s->getShopdate() << "\n";               // Shopitem에서 id, 고객명, 제품명, 가격, 고객id, 제품id, 구매일, 수량, 옵션에 대한 정보를 텍스트 파일에 저장
    }
    file.close( );                                                              // 파일 닫기
}

void ShopManagerForm::get_Product_Info(int id)                                  /*get_Product_Info 슬롯*/
{

    QString ProductName, Price, ProductType, Option;

    ProductName = pm->getList().find(id).value()->getProductName();
    Price = pm->getList().find(id).value()->getPrice();
    ProductType = pm->getList().find(id).value()->getProductType();
    Option = pm->getList().find(id).value()->getOption();   // productList에서 키 값과 일치하는 ProductItem을 가져와 제품명, 가격, 제품종류, 옵션에 대한 정보를 각각의 변수에 저장

    QTreeWidgetItem* item = new QTreeWidgetItem(ui->productTreeWidget);
    item->setText(0, QString::number(id));
    item->setText(1, ProductName);
    item->setText(2, Price);
    item->setText(3, ProductType);
    item->setText(4, Option);                                                   // QTreeWidgetItem을 만들어서 해당 정보들을 삽입

    ui->productTreeWidget->addTopLevelItem(item);                               // QTreeWidgetItem을 productTreeWidget의 탑레벨로 옮김
}

void ShopManagerForm::productTreeWidget_clear()                                 /*productTreeWidget_clear() 슬롯*/
{
    ui->productTreeWidget->clear();                                             // productTreeWidget 창 비움
}

int ShopManagerForm::makeId( )                                                  /*id 자동생성*/
{
    if(shopList.size( ) == 0) {
        return 100;                                                             // shopList에 내용이 없으면 100부터 시작
    } else {
        auto id = shopList.lastKey();
        return ++id;                                                            // 그렇지 않으면 shopList의 마지막 키 값에서 1을 더해 리턴
    }
}

void ShopManagerForm::removeItem()                                              /*removeItem 슬롯*/
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();                      // 트리위젯에서 현재 ShopItem 가져옴
    if(item != nullptr) {
        shopList.remove(item->text(0).toInt());                                 // 키 값에 해당하는 ShopItem 삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));    // 가장 탑레벨의 인덱스 값을 반환
        ui->treeWidget->update();                                               // 트리위젯 갱신
        ui->idLineEdit->clear();                                                // idLineEidt 창 비움
    }
}

void ShopManagerForm::removeOption()                                            /*removeOption 슬롯*/
{
    ui->optionComboBox->clear();                                                // optionComboBox의 내용 비움
}

void ShopManagerForm::showContextMenu(const QPoint &pos)                        /*showContextMenu 슬롯*/
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);                        // 전역좌표로 만들어서 가져옴
    menu->exec(globalPos);                                                      // 마우스 커서 좌표에서 메뉴 창을 띄움
}

void ShopManagerForm::on_searchPushButton_clicked()                             /*search 버튼 누를 경우*/
{
    ui->searchTreeWidget->clear();                                              // searchTreeWidget 창 비우기

    int i = ui->searchComboBox->currentIndex();                                 // sarchComboBox의 인덱스 값 가져옴
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains                   // 플래그로 대소문자를 구분하여 문자열 비교
                   : Qt::MatchCaseSensitive;

    auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);    // 트리위젯에서 searchLineEdit에서 입력한 글자와 같은 항목을 가져옴

    foreach(auto i, items)                                                      // 검색한 항목이 들어있는 ShopItem 목록을 가져옴
    {
        ShopItem* s = static_cast<ShopItem*>(i);
        int id = s->id();
        int clientID = s->getClientID();
        int productID = s->getProductID();
        QString shopDate = s->getShopdate();
        QString quantity = s->getQuantity();
        QString option = s->getOption();
        QString cname = cm->getList().find(clientID).value()->getName();
        QString pname = pm->getList().find(productID).value()->getProductName();
        QString price = pm->getList().find(productID).value()->getPrice();  // ShopItem에서 id, 고객id, 제품id, 구매일, 수량, 옵션, 고객명, 제품명, 가격 정보를 가져와서 변수에 저장
        ShopItem* item = new ShopItem(id, clientID, cname, productID, pname, shopDate, quantity, option, price);   // 가져온 정보들로 ShopItem 정의
        ui->searchTreeWidget->addTopLevelItem(item);                        // ShopItem을 searchTreeWidget의 탑레벨로 옮김
    }
}

void ShopManagerForm::on_addPushButton_clicked()                                /*Add 버튼 누를 경우*/
{
    int clientID, productID;
    QString shopDate, quantity, option, cname, pname, price;
    int id = makeId( );                                                         // id 자동생성
    clientID = ui->clientIDLineEdit->text().toInt();
    productID = ui->productIDLineEdit->text().toInt();
    shopDate = ui->shopDateEdit->text();
    quantity = ui->quantitySpinBox->text();
    option = ui->optionComboBox->currentText();
    cname = cm->getList().find(clientID).value()->getName();
    pname = pm->getList().find(productID).value()->getProductName();
    price = pm->getList().find(productID).value()->getPrice();          // 각각의 LineEidt에 적힌 id, 고객id, 제품id, 구매일, 수량, 옵션, 고객명, 제품명, 가격 정보를 변수에 저장
    ShopItem* s = new ShopItem(id, clientID, cname, productID, pname, shopDate, quantity, option, price);      // 각각의 정보들로 Shopitem 정의
    shopList.insert(id, s);                                              // clientList에 ShopItem 삽입
    ui->treeWidget->addTopLevelItem(s);                                  // treeWidget의 탑레벨로 옮김
}

void ShopManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)      /*treeWidget에서 항목을 클릭할 경우*/
{
    Q_UNUSED(column);                                                                   // 경고메세지 안띄우게 함
    ui->idLineEdit->setText(item->text(0));
    ui->clientIDLineEdit->setText(item->text(6));
    ui->productIDLineEdit->setText(item->text(7));
    ui->shopDateEdit->setDate(QDate::fromString(item->text(5)));
    ui->quantitySpinBox->setValue(item->text(4).toInt());                               // 선택된 항목의 id, 고객id, 제품id, 구매일, 수량을 lineEidt에 표시
    ui->optionComboBox->clear();                                                        // 옵션 comboBox 내용 비움
    ui->optionComboBox->addItem(item->text(3));                                         // 옵션 comboBox에 옵션 추가
}

void ShopManagerForm::on_productTreeWidget_itemClicked(QTreeWidgetItem *item, int column)    /*productTreeWidget의 항목을 클릭했을 때*/
{
    Q_UNUSED(column);                                                                   // 경고메세지 안띄우게 함
    ui->productIDLineEdit->setText(item->text(0));                                      // productIDLineEidt에 항목의 아이디 표시
    list.clear();                                                                       // 옵션을 '/'단위로 구분하기 위한 리스트 내용 비움
    ui->optionComboBox->clear();                                                        // 옵션 comboBox 내용 비움
    list = pm->getList().find(item->text(0).toInt()).value()->getOption().split("/");   // 옵션을 '/'단위로 구분해서 리스트에 삽입
    foreach(auto i, list)
    {
        ui->optionComboBox->addItem(i);                                                 // 리스트에 있는 옵션을 옵션comboBox에 삽입
    }
}

void ShopManagerForm::on_searchProductPushButton_clicked()                              /*searchProduct 버튼 누를 경우*/
{
    ui->searchProductTreeWidget->clear();                                               // searchTreeWidget 창 비우기

    int i = ui->searchProductComboBox->currentIndex();                                  // sarchComboBox의 인덱스 값 가져옴
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains                           // 플래그로 대소문자 구분하여 문자열 비교
                   : Qt::MatchCaseSensitive;

    auto items = ui->productTreeWidget->findItems(ui->searchProductLineEdit->text(), flag, i);   // 검색한 내용이 들어있는 ShopItem 가져옴

    foreach(auto i, items)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->searchProductTreeWidget);
        item->setText(0, i->text(0));
        item->setText(1, i->text(1));
        item->setText(2, i->text(2));
        item->setText(3, i->text(3));
        item->setText(4, i->text(4));

        ui->searchTreeWidget->addTopLevelItem(item);                            // 검색한 Shopitem에서 각각의 정보를 가져와 searchTreeWidget의 탑레벨로 옮김
    }
}

void ShopManagerForm::on_searchProductTreeWidget_itemClicked(QTreeWidgetItem *item, int column)     /*searchProdcutTreeWidget의 항목 클릭할 경우*/
{
    Q_UNUSED(column);                                                                               // 경고메세지 안띄움
    ui->productIDLineEdit->setText(item->text(0));                                                  // productIDLineEidt의 id를 lineEidt에 표시
    list.clear();                                                                                   // 옵션을 구분하기 위한 리스트 비움
    ui->optionComboBox->clear();                                                                    // 옵션 comboBox 비움
    list = pm->getList().find(item->text(0).toInt()).value()->getOption().split("/");               // 옵션을 '/'단위로 구분하여 리스트에 삽입
    foreach(auto i, list)
    {
        ui->optionComboBox->addItem(i);                                                             // 옵션 comboBox에 리스트 내용 삽입
    }
}

const QMap<int, ShopItem*>& ShopManagerForm::getList()                                           /*getList 함수*/
{
    return shopList;                                                                             // shopList를 읽기전용으로 리턴
}
