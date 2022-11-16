#pragma once
#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string.h>
#include "client.h"
#include "product.h"
using namespace std;

class Shop
{
public:
	Shop(int myshopID, int clientID, int itemID, string myshopdate, string myquantity, string myoption);

	string getShopdate() const;													// 구매날짜 리턴하는 함수
	string getQuantity() const;													// 구매수량 리턴하는 함수
	string getOption() const;													// 주문 옵션 리턴하는 함수
	int getShopID() const;														// 주문번호 리턴하는 함수
	int getClientID() const;													// 고객ID 리턴하는 함수
	int getItemID() const;														// 상품번호 리턴하는 함수
	void setShopdate(string& myshopdate);										// 구매날짜 수정하는 함수
	void setQuantity(string& myquantity);										// 구매수량 리턴하는 함수
	void setOption(string& myoption);											// 주문 옵션 리턴하는 함수
	bool operator==(int) const;													// int형에 해당되는 대입 연산자
	bool operator==(string) const;												// string형에 해당되는 대입 연산자
private:
	string shopdate;
	string quantity;
	int shopID;
	int clientID;
	int itemID;
	string price;
	string option;
	string item;
};
#endif