/********************************************************************************
** Form generated from reading UI file 'productmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGERFORM_H
#define UI_PRODUCTMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
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

class Ui_ProductManagerForm
{
public:
    QHBoxLayout *horizontalLayout_2;
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
    QLineEdit *productNameLineEdit;
    QLabel *label_3;
    QLineEdit *priceLineEdit;
    QLabel *label_4;
    QLineEdit *productTypeLineEdit;
    QLabel *label_6;
    QLineEdit *optionLineEdit;
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

    void setupUi(QWidget *ProductManagerForm)
    {
        if (ProductManagerForm->objectName().isEmpty())
            ProductManagerForm->setObjectName(QString::fromUtf8("ProductManagerForm"));
        ProductManagerForm->resize(871, 498);
        horizontalLayout_2 = new QHBoxLayout(ProductManagerForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(ProductManagerForm);
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

        productNameLineEdit = new QLineEdit(Input);
        productNameLineEdit->setObjectName(QString::fromUtf8("productNameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, productNameLineEdit);

        label_3 = new QLabel(Input);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        priceLineEdit = new QLineEdit(Input);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, priceLineEdit);

        label_4 = new QLabel(Input);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        productTypeLineEdit = new QLineEdit(Input);
        productTypeLineEdit->setObjectName(QString::fromUtf8("productTypeLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, productTypeLineEdit);

        label_6 = new QLabel(Input);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        optionLineEdit = new QLineEdit(Input);
        optionLineEdit->setObjectName(QString::fromUtf8("optionLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, optionLineEdit);


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

        horizontalLayout_2->addWidget(splitter);


        retranslateUi(ProductManagerForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProductManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ProductManagerForm)
    {
        ProductManagerForm->setWindowTitle(QCoreApplication::translate("ProductManagerForm", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("ProductManagerForm", "ProductManager", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ProductManagerForm", "Option", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        label->setText(QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        label_3->setText(QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        label_4->setText(QCoreApplication::translate("ProductManagerForm", "ProductType", nullptr));
        label_6->setText(QCoreApplication::translate("ProductManagerForm", "Option", nullptr));
        addPushButton->setText(QCoreApplication::translate("ProductManagerForm", "Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ProductManagerForm", "Modify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Input), QCoreApplication::translate("ProductManagerForm", "Tab 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = searchTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ProductManagerForm", "Option", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ProductManagerForm", "Option", nullptr));
        searchComboBox->setItemText(4, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ProductManagerForm", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Search), QCoreApplication::translate("ProductManagerForm", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagerForm: public Ui_ProductManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGERFORM_H
