/********************************************************************************
** Form generated from reading UI file 'clientmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMANAGERFORM_H
#define UI_CLIENTMANAGERFORM_H

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

class Ui_ClientManagerForm
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
    QLineEdit *nameLineEdit;
    QLabel *label_3;
    QLineEdit *phoneNumberLineEdit;
    QLabel *label_4;
    QLineEdit *addressLineEdit;
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

    void setupUi(QWidget *ClientManagerForm)
    {
        if (ClientManagerForm->objectName().isEmpty())
            ClientManagerForm->setObjectName(QString::fromUtf8("ClientManagerForm"));
        ClientManagerForm->resize(635, 404);
        horizontalLayout_2 = new QHBoxLayout(ClientManagerForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(ClientManagerForm);
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

        nameLineEdit = new QLineEdit(Input);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameLineEdit);

        label_3 = new QLabel(Input);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        phoneNumberLineEdit = new QLineEdit(Input);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneNumberLineEdit);

        label_4 = new QLabel(Input);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        addressLineEdit = new QLineEdit(Input);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addressLineEdit);


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


        retranslateUi(ClientManagerForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ClientManagerForm)
    {
        ClientManagerForm->setWindowTitle(QCoreApplication::translate("ClientManagerForm", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("ClientManagerForm", "ClientManager", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ClientManagerForm", "PhoneNumber", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        label->setText(QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("ClientManagerForm", "PhoneNumber", nullptr));
        label_4->setText(QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        addPushButton->setText(QCoreApplication::translate("ClientManagerForm", "Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ClientManagerForm", "Modify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Input), QCoreApplication::translate("ClientManagerForm", "Tab 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = searchTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ClientManagerForm", "PhoneNumber", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ClientManagerForm", "PhoneNumber", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ClientManagerForm", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Search), QCoreApplication::translate("ClientManagerForm", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientManagerForm: public Ui_ClientManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMANAGERFORM_H
