/********************************************************************************
** Form generated from reading UI file 'shopmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPMANAGERFORM_H
#define UI_SHOPMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopManagerForm
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QWidget *Input;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *idLineEdit;
    QLabel *label_2;
    QLineEdit *clientIDLineEdit;
    QLabel *label_3;
    QLineEdit *productIDLineEdit;
    QLabel *label_4;
    QLineEdit *shopDateLineEdit;
    QLabel *label_6;
    QLineEdit *optionLineEdit;
    QLabel *label_7;
    QLineEdit *quantityLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QWidget *Search;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *searchTreeWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;

    void setupUi(QWidget *ShopManagerForm)
    {
        if (ShopManagerForm->objectName().isEmpty())
            ShopManagerForm->setObjectName(QString::fromUtf8("ShopManagerForm"));
        ShopManagerForm->resize(812, 478);
        gridLayout = new QGridLayout(ShopManagerForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(ShopManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(18);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        treeWidget = new QTreeWidget(layoutWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        splitter->addWidget(layoutWidget);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Input = new QWidget();
        Input->setObjectName(QString::fromUtf8("Input"));
        verticalLayout_3 = new QVBoxLayout(Input);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Input);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        idLineEdit = new QLineEdit(Input);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        label_2 = new QLabel(Input);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        clientIDLineEdit = new QLineEdit(Input);
        clientIDLineEdit->setObjectName(QString::fromUtf8("clientIDLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, clientIDLineEdit);

        label_3 = new QLabel(Input);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        productIDLineEdit = new QLineEdit(Input);
        productIDLineEdit->setObjectName(QString::fromUtf8("productIDLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, productIDLineEdit);

        label_4 = new QLabel(Input);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        shopDateLineEdit = new QLineEdit(Input);
        shopDateLineEdit->setObjectName(QString::fromUtf8("shopDateLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, shopDateLineEdit);

        label_6 = new QLabel(Input);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        optionLineEdit = new QLineEdit(Input);
        optionLineEdit->setObjectName(QString::fromUtf8("optionLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, optionLineEdit);

        label_7 = new QLabel(Input);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        quantityLineEdit = new QLineEdit(Input);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, quantityLineEdit);


        verticalLayout_3->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(17, 152, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPushButton = new QPushButton(Input);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(Input);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        horizontalLayout->addWidget(modifyPushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget->addTab(Input, QString());
        Search = new QWidget();
        Search->setObjectName(QString::fromUtf8("Search"));
        verticalLayout_4 = new QVBoxLayout(Search);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        searchTreeWidget = new QTreeWidget(Search);
        searchTreeWidget->setObjectName(QString::fromUtf8("searchTreeWidget"));

        verticalLayout_4->addWidget(searchTreeWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        searchComboBox = new QComboBox(Search);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));

        horizontalLayout_3->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(Search);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout_3->addWidget(searchLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        searchPushButton = new QPushButton(Search);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));

        verticalLayout_2->addWidget(searchPushButton);


        verticalLayout_4->addLayout(verticalLayout_2);

        tabWidget->addTab(Search, QString());
        splitter->addWidget(tabWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(ShopManagerForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShopManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ShopManagerForm)
    {
        ShopManagerForm->setWindowTitle(QCoreApplication::translate("ShopManagerForm", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("ShopManagerForm", "ShopManager", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("ShopManagerForm", "TotalPrice", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("ShopManagerForm", "ProductID", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("ShopManagerForm", "ShopDate", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ShopManagerForm", "Option", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ShopManagerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        label->setText(QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("ShopManagerForm", "ClientID", nullptr));
        label_3->setText(QCoreApplication::translate("ShopManagerForm", "ProductID", nullptr));
        label_4->setText(QCoreApplication::translate("ShopManagerForm", "ShopDate", nullptr));
        label_6->setText(QCoreApplication::translate("ShopManagerForm", "Option", nullptr));
        label_7->setText(QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        addPushButton->setText(QCoreApplication::translate("ShopManagerForm", "Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ShopManagerForm", "Modify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Input), QCoreApplication::translate("ShopManagerForm", "Tab 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = searchTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(7, QCoreApplication::translate("ShopManagerForm", "TotalPrice", nullptr));
        ___qtreewidgetitem1->setText(6, QCoreApplication::translate("ShopManagerForm", "ProductID", nullptr));
        ___qtreewidgetitem1->setText(5, QCoreApplication::translate("ShopManagerForm", "ShopDate", nullptr));
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ShopManagerForm", "Option", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ShopManagerForm", "Name", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ShopManagerForm", "Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ShopManagerForm", "Option", nullptr));
        searchComboBox->setItemText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        searchComboBox->setItemText(5, QCoreApplication::translate("ShopManagerForm", "ShopDate", nullptr));
        searchComboBox->setItemText(6, QCoreApplication::translate("ShopManagerForm", "ProductID", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ShopManagerForm", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Search), QCoreApplication::translate("ShopManagerForm", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopManagerForm: public Ui_ShopManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPMANAGERFORM_H
