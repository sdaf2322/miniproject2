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

	string getShopdate() const;													// ���ų�¥ �����ϴ� �Լ�
	string getQuantity() const;													// ���ż��� �����ϴ� �Լ�
	string getOption() const;													// �ֹ� �ɼ� �����ϴ� �Լ�
	int getShopID() const;														// �ֹ���ȣ �����ϴ� �Լ�
	int getClientID() const;													// ��ID �����ϴ� �Լ�
	int getItemID() const;														// ��ǰ��ȣ �����ϴ� �Լ�
	void setShopdate(string& myshopdate);										// ���ų�¥ �����ϴ� �Լ�
	void setQuantity(string& myquantity);										// ���ż��� �����ϴ� �Լ�
	void setOption(string& myoption);											// �ֹ� �ɼ� �����ϴ� �Լ�
	bool operator==(int) const;													// int���� �ش�Ǵ� ���� ������
	bool operator==(string) const;												// string���� �ش�Ǵ� ���� ������
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