#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

class Product
{
public:
	Product(int myID, string myproductName, string myprice, string myoption, string myitem);

	string getProductName() const;												// 상품명 리턴하는 함수
	string getPrice() const;													// 상품 가격 리턴하는 함수
	string getOption() const;													// 상품 옵션 리턴하는 함수
	string getItem() const;														// 품목 리턴하는 함수
	int getID() const;															// 상품번호 리턴하는 함수
	void setProductName(string& myproductName);									// 상품명 수정하는 함수
	void setPrice(string& mypirce);												// 상품 가격 수정하는 함수
	void setOption(string& myoption);											// 상품 옵션 수정하는 함수
	void setItem(string& myitem);												// 품목을 수정하는 함수
	bool operator==(int) const;													// int형에 대한 대입 연산자
	bool operator==(string) const;												// string에 대한 대입 연산자
	void displayInfo() const;													// 상품 정보를 출력하는 함수
private:
	int itemID;
	string productName;
	string price;
	string option;
	string item;
};
#endif