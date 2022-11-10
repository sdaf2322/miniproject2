#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clientmanagerform.h"
#include "productmanagerform.h"
#include "shopmanagerform.h"
#include "serverform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serverForm = new ServerForm(this);
    serverForm->setWindowTitle(tr("Chatting Server"));                                                // ServerForm 클래스를 만들고 윈도우 타이틀 설정

    clientForm = new ClientManagerForm(this);
    productForm = new ProductManagerForm(this);
    shopForm = new ShopManagerForm(this, clientForm, productForm);                                     // ClientManager, ProductManager, ShopManager 클래스 만듦

    connect(clientForm, SIGNAL(destroyed()), clientForm, SLOT(deleteLater()));                         // destroyed 시그널 발생시 ClientManager 창 닫음
    clientForm->setWindowTitle(tr("Client Info"));                                                     // ClientManager 윈도우 타이틀 설정

    connect(productForm, SIGNAL(destroyed()), productForm, SLOT(deleteLater()));                       // destroyed 시그널 발생시 ProductManager 창 닫음
    connect(productForm, SIGNAL(Add_Product_Info(int)), shopForm, SLOT(get_Product_Info(int)));        // Add_Product_Info 시그널 발생시 get_Product_Info 슬롯 발생
    connect(productForm, SIGNAL(Remove_Product_Info()), shopForm, SLOT(productTreeWidget_clear()));
    connect(productForm, SIGNAL(Remove_productTreeWidget_Item()), shopForm, SLOT(removeOption())); // Remove_productTreeWidget_Item() 시그널 발생시 removeOption() 슬롯 발생

    productForm->setWindowTitle(tr("Product Info"));                                                    // ProductManager 윈도우 타이틀 생성

    connect(shopForm, SIGNAL(destroyed()), shopForm, SLOT(deleteLater()));                              // destroyed 시그널 발생시 Shopmanager 창 닫음

    shopForm->setWindowTitle(tr("Shop Info"));                                                          // ShopManager 윈도우 타이틀 설정

    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);
    ui->mdiArea->addSubWindow(productForm);
    ui->mdiArea->addSubWindow(shopForm);
    ui->mdiArea->addSubWindow(serverForm);
    ui->mdiArea->setActiveSubWindow(cw);                                                                // mdiArea에 각각의 클래스를 추가하고 set

    connect(clientForm, SIGNAL(clientAdded(int,QString)), serverForm, SLOT(addClient(int,QString)));    // clientAdded 시그널 발생시 serverForm의 addClient 슬롯 발생
    productForm->LoadData();
    clientForm->LoadData();
    shopForm->LoadData();                                                                               // 각각의 클래스에 해당되는 텍스트 파일 불러옴
}

MainWindow::~MainWindow()                                                /*MainWindow 소멸자*/
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()                             /*Client 액션을 누를 경우*/
{
    if(clientForm != nullptr) {
        clientForm->setFocus();                                          // ClientManager 창을 띄움
    }
}

void MainWindow::on_actionProduct_triggered()                            /*Product 액션을 누를 경우*/
{
    if(productForm != nullptr) {
        productForm->setFocus();                                         // ProductManager 창을 띄움
    }
}

void MainWindow::on_actionShop_triggered()                               /*Shop 액션을 누를 경우*/
{
    if(shopForm != nullptr) {
        shopForm->setFocus();                                            // ShopManagerForm 창을 띄움
    }
}

void MainWindow::on_actionChatting_triggered()                           /*Chatting 액션을 누를 경우*/
{
    if(serverForm != nullptr) {
        serverForm->setFocus();                                          // ServcerForm 창을 띄움
    }
}


