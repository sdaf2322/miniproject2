#include "product.h"
#include <iostream>
#include <iomanip>

Product::Product(int myID, string myproductName, string myprice, string myoption, string myitem)
	: itemID(myID), productName(myproductName), price(myprice), option(myoption), item(myitem)
{

}

// 상품명 리턴
string Product::getProductName() const
{
	return productName;
}

// 상품 가격 리턴 
string Product::getPrice() const
{
	return price;
}

// 상품번호 리턴
int Product::getID() const
{
	return itemID;
}

// 상품명 수정
void Product::setProductName(string& myproductName)
{
	productName = myproductName;
}

// 상품 가격 수정
void Product::setPrice(string& myprice) 
{
	price = myprice;
}

// 상품 옵션 리턴
string Product::getOption() const
{
	return option;
}

// 상품 옵션 수정
void Product::setOption(string& myoption)
{
	option = myoption;
}

// 품목 리턴
string Product::getItem() const
{
	return item;
}

// 품목 수정
void Product::setItem(string& myitem)
{
	item = myitem;
}

// 상품 정보 출력
void Product::displayInfo() const
{
	cout << setw(5) << setfill('0') << right << itemID << " | " << left;
	cout << setw(12) << setfill(' ') << productName << " | ";
	cout << setw(12) << price << " | ";
	cout << setw(15) << item << " | ";
	cout << option << endl;
}

// int형에 대한 대입 연산자
bool Product::operator==(int id) const
{
	return (this->itemID == id);
}

// string에 대한 대입 연산자
bool Product::operator==(string str) const
{
	return (this->productName == str);
}