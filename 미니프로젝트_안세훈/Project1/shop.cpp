#include "shop.h"
#include "client.h"
#include "product.h"
#include <iostream>
#include <iomanip>
using namespace std;

Shop::Shop(int myshopID, int myclientID, int myitemID, string myshopdate, string myquantity, string myoption)
	: shopID(myshopID), clientID(myclientID), itemID(myitemID), shopdate(myshopdate), quantity(myquantity), option(myoption)
{

}

// 쇼핑날짜 리턴
string Shop::getShopdate() const
{
	return shopdate;
}

// 구매수량 리턴
string Shop::getQuantity() const
{
	return quantity;
}

// 주문번호 리턴
int Shop::getShopID() const
{
	return shopID;
}

// 고객ID 리턴
int Shop::getClientID() const
{
	return clientID;
}

// 상품번호 리턴
int Shop::getItemID() const
{
	return itemID;
}

// 구매날짜 수정
void Shop::setShopdate(string& myshopdate)
{
	shopdate = myshopdate;
}

// 구매수량 수정
void Shop::setQuantity(string& myquantity)
{
	quantity = myquantity;
}

// 상품 옵션 리턴
string Shop::getOption() const
{
	return option;
}

// 상품 옵션 수정
void Shop::setOption(string& myoption)
{
	option = myoption;
}

// int형에 대한 대입 연산자
bool Shop::operator==(int id) const
{
	return (this->itemID == id);
}

// string에 대한 대입 연산자
bool Shop::operator==(string str) const
{
	return (this->shopdate == str);
}