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

	string getProductName() const;												// ��ǰ�� �����ϴ� �Լ�
	string getPrice() const;													// ��ǰ ���� �����ϴ� �Լ�
	string getOption() const;													// ��ǰ �ɼ� �����ϴ� �Լ�
	string getItem() const;														// ǰ�� �����ϴ� �Լ�
	int getID() const;															// ��ǰ��ȣ �����ϴ� �Լ�
	void setProductName(string& myproductName);									// ��ǰ�� �����ϴ� �Լ�
	void setPrice(string& mypirce);												// ��ǰ ���� �����ϴ� �Լ�
	void setOption(string& myoption);											// ��ǰ �ɼ� �����ϴ� �Լ�
	void setItem(string& myitem);												// ǰ���� �����ϴ� �Լ�
	bool operator==(int) const;													// int���� ���� ���� ������
	bool operator==(string) const;												// string�� ���� ���� ������
	void displayInfo() const;													// ��ǰ ������ ����ϴ� �Լ�
private:
	int itemID;
	string productName;
	string price;
	string option;
	string item;
};
#endif