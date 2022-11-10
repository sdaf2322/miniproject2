/********************************************************************************
** Form generated from reading UI file 'serverform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERFORM_H
#define UI_SERVERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTreeWidget *messageTreeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeWidget *clientTreeWidget;

    void setupUi(QWidget *ServerForm)
    {
        if (ServerForm->objectName().isEmpty())
            ServerForm->setObjectName(QString::fromUtf8("ServerForm"));
        ServerForm->resize(378, 313);
        horizontalLayout_2 = new QHBoxLayout(ServerForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(ServerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        messageTreeWidget = new QTreeWidget(layoutWidget);
        messageTreeWidget->setObjectName(QString::fromUtf8("messageTreeWidget"));

        verticalLayout->addWidget(messageTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        clientTreeWidget = new QTreeWidget(layoutWidget1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("State"));
        clientTreeWidget->setHeaderItem(__qtreewidgetitem);
        clientTreeWidget->setObjectName(QString::fromUtf8("clientTreeWidget"));

        verticalLayout_2->addWidget(clientTreeWidget);

        splitter->addWidget(layoutWidget1);

        horizontalLayout_2->addWidget(splitter);


        retranslateUi(ServerForm);

        QMetaObject::connectSlotsByName(ServerForm);
    } // setupUi

    void retranslateUi(QWidget *ServerForm)
    {
        ServerForm->setWindowTitle(QCoreApplication::translate("ServerForm", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("ServerForm", "Log", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = messageTreeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("ServerForm", "Time", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ServerForm", "Message", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ServerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ServerForm", "ID", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ServerForm", "Port", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ServerForm", "IP", nullptr));
        pushButton->setText(QCoreApplication::translate("ServerForm", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ServerForm", "Save", nullptr));
        label->setText(QCoreApplication::translate("ServerForm", "Client List", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = clientTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ServerForm", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerForm: public Ui_ServerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERFORM_H
