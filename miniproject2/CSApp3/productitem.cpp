#include "productitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ProductItem::ProductItem(int id, QString productName, QString price, QString productType, QString option)       /*ProductItem 생성자*/
{
    setText(0, QString::number(id));
    setText(1, productName);
    setText(2, price);
    setText(3, productType);
    setText(4, option);
}                                                                                              // id, 제품명, 가격, 제품종류, 옵션에 대한 정보를 화면에 표시

QString ProductItem::getProductName() const
{
    return text(1);                                                                            // 제품명에 대한 정보를 가져옴
}

void ProductItem::setProductName(QString& productName)
{
    setText(1, productName);                                                                   // 제품명에 대한 정보를 수정
}

QString ProductItem::getPrice() const
{
    return text(2);                                                                            // 가격에 대한 정보를 가져옴
}

void ProductItem::setPrice(QString& price)
{
    setText(2, price);                                                                         // 가격에 대한 정보를 수정
}

QString ProductItem::getProductType() const
{
    return text(3);                                                                            // 제품종류에 대한 정보를 가져옴
}

void ProductItem::setProductType(QString& productType)
{
    setText(3, productType);                                                                   // 제품종류에 대한 정보를 수정
}

QString ProductItem::getOption() const
{
    return text(4);                                                                            // 옵션에 대한 정보를 가져옴
}

void ProductItem::setOption(QString& option)
{
    setText(4, option);                                                                        // 옴션에 대한 정보를 수정
}

int ProductItem::getID() const
{
    return text(0).toInt();                                                                    // id에 대한 정보를 가져옴
}

// Define copy assignment operator.
bool ProductItem::operator==(const ProductItem &other) const {                          // 대입연산자로 다른 생성자에서 제품명에 대한 정보를 받아올 수 있음
    return (this->text(1) == other.text(1));
}
