#include "shopitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ShopItem::ShopItem(int id, int clientID, QString cname, int productID, QString pname, QString shopDate, QString quantity, QString option, QString price)
{                                                                                     /*ShopItem 생성자*/
    setText(0, QString::number(id));
    setText(1, cname);
    setText(2, pname);
    setText(3, option);
    setText(4, quantity);
    setText(5, shopDate);
    setText(6, QString::number(clientID));
    setText(7, QString::number(productID));
    setText(8, QString::number(price.toInt() * quantity.toInt()));
}                                                                 // id, 고객명, 제품종류, 옵션, 수량, 구매날짜, 고객id, 제품id, 쇼핑id에 대한 정보를 화면에 출력

int ShopItem::getClientID() const
{
    return text(6).toInt();                                       // 고객id에 대한 정보를 가져옴
}

int ShopItem::getProductID() const
{
    return text(7).toInt();                                       // 제품id에 대한 정보를 가져옴
}

QString ShopItem::getShopdate() const
{
    return text(5);                                               // 쇼핑날짜에 대한 정보를 가져옴
}

QString ShopItem::getQuantity() const
{
    return text(4);                                               // 수량에 대한 정보를 가져옴
}

QString ShopItem::getOption() const
{
    return text(3);                                               // 옵션에 대한 정보를 가져옴
}

void ShopItem::setShopdate(QString& shopDate)
{
    setText(5, shopDate);                                         // 쇼핑날짜에 대한 정보를 수정
}

void ShopItem::setQuantity(QString& quantity)
{
    setText(4, quantity);                                         // 수량에 대한 정보를 수정
}

void ShopItem::setOption(QString& option)
{
    setText(3, option);                                           // 옵션에 대한 정보를 수정
}

int ShopItem::id() const
{
    return text(0).toInt();                                       // id에 대한 정보를 가져옴
}

// Define copy assignment operator.
bool ShopItem::operator==(const ShopItem &other) const {          // 대입연산자로 다른 생성자에서 고객명에 대한 정보를 받아올 수 있음
    return (this->text(1) == other.text(1));
}
