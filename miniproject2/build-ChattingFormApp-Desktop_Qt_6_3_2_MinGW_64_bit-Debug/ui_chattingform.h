/********************************************************************************
** Form generated from reading UI file 'chattingform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTINGFORM_H
#define UI_CHATTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChattingForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *mainLayout;
    QHBoxLayout *serverLayout;
    QLineEdit *name;
    QLineEdit *serverAddress;
    QLineEdit *serverPort;
    QPushButton *connectButton;
    QTextEdit *message;
    QHBoxLayout *inputLayout;
    QLineEdit *inputLine;
    QPushButton *sentButton;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;

    void setupUi(QWidget *ChattingForm)
    {
        if (ChattingForm->objectName().isEmpty())
            ChattingForm->setObjectName(QString::fromUtf8("ChattingForm"));
        ChattingForm->resize(351, 300);
        horizontalLayout_2 = new QHBoxLayout(ChattingForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mainLayout = new QVBoxLayout();
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        serverLayout = new QHBoxLayout();
        serverLayout->setObjectName(QString::fromUtf8("serverLayout"));
        name = new QLineEdit(ChattingForm);
        name->setObjectName(QString::fromUtf8("name"));

        serverLayout->addWidget(name);

        serverAddress = new QLineEdit(ChattingForm);
        serverAddress->setObjectName(QString::fromUtf8("serverAddress"));

        serverLayout->addWidget(serverAddress);

        serverPort = new QLineEdit(ChattingForm);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));

        serverLayout->addWidget(serverPort);

        connectButton = new QPushButton(ChattingForm);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        serverLayout->addWidget(connectButton);


        mainLayout->addLayout(serverLayout);

        message = new QTextEdit(ChattingForm);
        message->setObjectName(QString::fromUtf8("message"));

        mainLayout->addWidget(message);

        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        inputLine = new QLineEdit(ChattingForm);
        inputLine->setObjectName(QString::fromUtf8("inputLine"));

        inputLayout->addWidget(inputLine);

        sentButton = new QPushButton(ChattingForm);
        sentButton->setObjectName(QString::fromUtf8("sentButton"));

        inputLayout->addWidget(sentButton);


        mainLayout->addLayout(inputLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        quitButton = new QPushButton(ChattingForm);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        buttonLayout->addWidget(quitButton);


        mainLayout->addLayout(buttonLayout);


        horizontalLayout_2->addLayout(mainLayout);


        retranslateUi(ChattingForm);

        QMetaObject::connectSlotsByName(ChattingForm);
    } // setupUi

    void retranslateUi(QWidget *ChattingForm)
    {
        ChattingForm->setWindowTitle(QCoreApplication::translate("ChattingForm", "Form", nullptr));
        connectButton->setText(QCoreApplication::translate("ChattingForm", "Log In", nullptr));
        sentButton->setText(QCoreApplication::translate("ChattingForm", "Send", nullptr));
        quitButton->setText(QCoreApplication::translate("ChattingForm", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChattingForm: public Ui_ChattingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTINGFORM_H
