#include "product.h"
#include <iostream>
#include <iomanip>

Product::Product(int myID, string myproductName, string myprice, string myoption, string myitem)
	: itemID(myID), productName(myproductName), price(myprice), option(myoption), item(myitem)
{

}

// ��ǰ�� ����
string Product::getProductName() const
{
	return productName;
}

// ��ǰ ���� ���� 
string Product::getPrice() const
{
	return price;
}

// ��ǰ��ȣ ����
int Product::getID() const
{
	return itemID;
}

// ��ǰ�� ����
void Product::setProductName(string& myproductName)
{
	productName = myproductName;
}

// ��ǰ ���� ����
void Product::setPrice(string& myprice) 
{
	price = myprice;
}

// ��ǰ �ɼ� ����
string Product::getOption() const
{
	return option;
}

// ��ǰ �ɼ� ����
void Product::setOption(string& myoption)
{
	option = myoption;
}

// ǰ�� ����
string Product::getItem() const
{
	return item;
}

// ǰ�� ����
void Product::setItem(string& myitem)
{
	item = myitem;
}

// ��ǰ ���� ���
void Product::displayInfo() const
{
	cout << setw(5) << setfill('0') << right << itemID << " | " << left;
	cout << setw(12) << setfill(' ') << productName << " | ";
	cout << setw(12) << price << " | ";
	cout << setw(15) << item << " | ";
	cout << option << endl;
}

// int���� ���� ���� ������
bool Product::operator==(int id) const
{
	return (this->itemID == id);
}

// string�� ���� ���� ������
bool Product::operator==(string str) const
{
	return (this->productName == str);
}