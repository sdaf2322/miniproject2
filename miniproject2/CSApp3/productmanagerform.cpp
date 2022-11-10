#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include "productitem.h"

#include <QFile>
#include <QMenu>

ProductManagerForm::ProductManagerForm(QWidget *parent) :                                       /*ProductManagerForm 생성자*/
    QWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);
    ui->idLineEdit->setDisabled(true);                                                          // idLineEidt 읽기전용으로 설정
    ui->optionLineEdit->setPlaceholderText("Please use the '/' to separate options.");          // optionLineEidt에 내용이 없으면 해당 텍스트 출력

    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);                                                              // ui에서 tree위젯과 tab위젯의 크기 비율 설정

    QAction* removeAction = new QAction(tr("&Remove"));                                         // removeAction 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));                             // removeAction 누르면 removeItem 슬롯 발생

    menu = new QMenu;
    menu->addAction(removeAction);                                                              // 메뉴 만들어서 removeAction 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);                                // 사용자가 정의한 메뉴를 정책으로 함

    // 트리위젯에서 오른쪽 마우스 키 누르면 shopContextMenu 슬롯 발생
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), SLOT(showContextMenu(QPoint)));

    // searchLineEdit에서 엔터키를 눌렀을 경우 on_searchPushButton_clicked()슬롯 발생
    connect(ui->searchLineEdit, SIGNAL(returnPressed()), SLOT(on_searchPushButton_clicked()));
}

void ProductManagerForm::LoadData()                                                             /*텍스트 파일에 저장된 내용 불러오기*/
{
    QFile file("productlist10.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;                                                                                 // 파일이 읽기전용이나 텍스트 파일이 아니면 리턴

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");                           // 텍스트 파일에 저장된 id, 제품명, 가격, 제품종류, 옵션 정보를 ','단위로 구분 해서 리스트에 저장
        if(row.size()) {
            int id = row[0].toInt();
            ProductItem* p = new ProductItem(id, row[1], row[2], row[3], row[4]);   // 텍스트 파일에서 불러온 id, 제품명, 가격, 제품종류, 옵션 정보로 ProductItem 재정의
            ui->treeWidget->addTopLevelItem(p);                                     // 해당 ProductItem를 treeWidget의 탑레벨로 옮김
            productList.insert(id, p);                                              // ProductItem을 productList에 삽입
            emit Add_Product_Info(id);                                              // Add_Product_Info 시그널 방출
        }
    }
    file.close( );                                                                  // 파일 닫기
}

ProductManagerForm::~ProductManagerForm()                                           /*텍스트 파일에 id, 제품명, 가격 제품종류, 옵션 정보를 저장*/
{
    delete ui;

    QFile file("productlist10.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;                                                                     // 파일이 쓰기전용이나 텍스트 파일이 아니면 리턴

    QTextStream out(&file);
    for (const auto& v : productList.values()) {                                    // productList에 들어있는 ProductItem들을 꺼냄
        ProductItem* p = v;
        out << p->getID() << ", " << p->getProductName() << ", ";
        out << p->getPrice() << ", ";
        out << p->getProductType() << ", ";
        out << p->getOption() << "\n";
    }                                                                               // 텍스트 파일에 id, 제품명, 가격, 제품종류, 옵션 정보를 저장
    file.close( );                                                                  // 파일 닫기
}

int ProductManagerForm::makeId( )                                                   /*id 자동생성*/
{
    if(productList.size( ) == 0) {
        return 100;                                                                 // productList에 내용이 없으면 100부터 시작
    } else {
        auto id = productList.lastKey();
        return ++id;                                                                // 그렇지 않으면 productList의 마지막 키 값을 가져와 1을 더해 리턴
    }
}

void ProductManagerForm::removeItem()                                               /*removeItem 슬롯*/
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();                          // 트리위젯에서 현재 ProductItem을 가져옴
    if(item != nullptr) {
        productList.remove(item->text(0).toInt());                                  // productList에서 현재 id에 해당하는 ProductItem을 제거
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));    // 가장 탑레벨의 인덱스 값을 반환
        ui->treeWidget->update();                                                   // 트리위젯 갱신
        ui->idLineEdit->clear();
        emit Remove_Product_Info();
        emit Remove_productTreeWidget_Item();                                       // Remove_productTreeWidget_Item 시그널 방출
    }
}

void ProductManagerForm::showContextMenu(const QPoint &pos)                         /*showContextMenu 슬롯*/
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);                            // 전역좌표로 만들어서 가져옴
    menu->exec(globalPos);                                                          // 마우스 커서 좌표에서 메뉴 창을 띄움
}

void ProductManagerForm::on_searchPushButton_clicked()                              /*search 버튼 누를 경우*/
{
    ui->searchTreeWidget->clear();                                                  // searchTreeWidget 창 비우기

    int i = ui->searchComboBox->currentIndex();                                     // sarchComboBox의 현재 인덱스 값 가져옴
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains                       // 플래그로 대소문자를 고려해 문자열이 일치하는지 비교
                   : Qt::MatchCaseSensitive;

    auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);    // 트리위젯에서 searchLineEdit에서 입력한 글자와 같은 ProductItem들을 가져옴

    foreach(auto i, items)
    {
        ProductItem* p = static_cast<ProductItem*>(i);
        int id = p->getID();
        QString productName = p->getProductName();
        QString price = p->getPrice();
        QString productType = p->getProductType();
        QString option = p->getOption();                             // productList에 저장된 ProductItem에서 id, 제품명, 가격, 제품종류, 옵션에 대한 내용 가져와 변수에 저장
        ProductItem* item = new ProductItem(id, productName, price, productType, option);           // 가져온 정보들로 ProductItem 재정의
        ui->searchTreeWidget->addTopLevelItem(item);                                                // searchTreeWidget의 탑레벨로 옮김
    }
}

void ProductManagerForm::on_modifyPushButton_clicked()                            /*Modify 버튼 누를 경우*/
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();                        // 현재 선택된 ProductItem 가져옴
    if(item != nullptr) {
        int key = item->text(0).toInt();
        ProductItem* p = productList[key];                                        // productList에서 키 값과 일치하는 ProductItem을 가져옴
        QString productName, price, productType, option;
        productName = ui->productNameLineEdit->text();                            // 라인에딧에 이름쓴거 name에 저장
        price = ui->priceLineEdit->text();
        productType = ui->productTypeLineEdit->text();
        option = ui->optionLineEdit->text();                                      // ProductItem에서 제품명, 가격, 제품종류, 옵션에 대한 정보를 가져와 변수에 저장
        p->setProductName(productName);
        p->setPrice(price);
        p->setProductType(productType);
        p->setOption(option);                                                     // 가져온 정보들로 ProductItem 재정의
        productList[key] = p;                                                     // ProductList에 재정의된 ProductItem 삽입
    }
}

void ProductManagerForm::on_addPushButton_clicked()                               /*Add 버튼 누를 경우*/
{
    QString productName, price, productType, option;
    int id = makeId( );                                                           // id 자동생성
    productName = ui->productNameLineEdit->text();
    price = ui->priceLineEdit->text();
    productType = ui->productTypeLineEdit->text();
    option = ui->optionLineEdit->text();                                          // 각각의 Line Edit에 쓴 제품명, 가격, 제품정보, 옵션에 대한 정보를 변수에 저장
    if(productName.length()) {
        ProductItem* p = new ProductItem(id, productName, price, productType, option);       // 가져온 정보들로 ProductItem 정의
        productList.insert(id, p);                                                           // productList에 ProductItem 삽입
        ui->treeWidget->addTopLevelItem(p);                                                  // treeWidget의 탑레벨로 옮김
        emit Add_Product_Info(id);                                                           // Add_Product_Info 시그널 방출
    }
}

void ProductManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)            /*treeWidget에서 항목을 선택할 경우*/
{
    Q_UNUSED(column);                                                                            // 경고메세지 안띄우게 함
    ui->idLineEdit->setText(item->text(0));
    ui->productNameLineEdit->setText(item->text(1));
    ui->priceLineEdit->setText(item->text(2));
    ui->productTypeLineEdit->setText(item->text(3));
    ui->optionLineEdit->setText(item->text(4));
}                                                                         // 선택된 항목의 id, 제품명, 가격, 제품종류, 옵션에 대한 정보를 각각의 LineEidt에 표시

ProductItem* ProductManagerForm::search(int id)                                     /*search함수*/
{
    auto it = productList.find(id);                                                 // productList에서 키 값과 일치하는 ProductItem을 가져옴
    return (it != productList.end() ? productList[id] : nullptr);                   // productList의 끝이 아니면 ProductItem을 반환, 그렇지 않으면 nullptr
}

const QMap<int, ProductItem*>& ProductManagerForm::getList()                        /*getList 함수*/
{
    return productList;                                                             // productList를 읽기전용으로 반환
}
