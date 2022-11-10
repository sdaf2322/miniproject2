#include "clientitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ClientItem::ClientItem(int id, QString name, QString phoneNumber, QString address)                  /*ClientItem 생성자*/
{
    setText(0, QString::number(id));
    setText(1, name);
    setText(2, phoneNumber);
    setText(3, address);
}                                                                                                   // id, 이름, 전화번호, 주소에 대한 정보를 화면에 표시

QString ClientItem::getName() const
{
    return text(1);                                                                                 // 이름에 대한 정보를 가져옴
}

void ClientItem::setName(QString& name)
{
    setText(1, name);                                                                               // 이름에 대한 정보를 수정
}

QString ClientItem::getPhoneNumber() const
{
    return text(2);                                                                                 // 전화번호에 대한 정보를 가져옴
}

void ClientItem::setPhoneNumber(QString& phoneNumber)
{
    setText(2, phoneNumber);                                                                        // 전화번호에 대한 정보를 수정
}

QString ClientItem::getAddress() const
{
    return text(3);                                                                                 // 주소에 대한 정보를 가져옴
}

void ClientItem::setAddress(QString& address)
{
    setText(3, address);                                                                            // 주소에 대한 정보를 수정
}

int ClientItem::getID() const
{
    return text(0).toInt();                                                                         // id에 대한 정보를 가져옴
}

// Define copy assignment operator.
bool ClientItem::operator==(const ClientItem &other) const {                                        // 대입연산자로 다른 생성자에서 이름에 대한 정보를 대입할 수 있음
    return (this->text(1) == other.text(1));
}
