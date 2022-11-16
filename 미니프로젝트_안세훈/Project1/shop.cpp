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

// ���γ�¥ ����
string Shop::getShopdate() const
{
	return shopdate;
}

// ���ż��� ����
string Shop::getQuantity() const
{
	return quantity;
}

// �ֹ���ȣ ����
int Shop::getShopID() const
{
	return shopID;
}

// ��ID ����
int Shop::getClientID() const
{
	return clientID;
}

// ��ǰ��ȣ ����
int Shop::getItemID() const
{
	return itemID;
}

// ���ų�¥ ����
void Shop::setShopdate(string& myshopdate)
{
	shopdate = myshopdate;
}

// ���ż��� ����
void Shop::setQuantity(string& myquantity)
{
	quantity = myquantity;
}

// ��ǰ �ɼ� ����
string Shop::getOption() const
{
	return option;
}

// ��ǰ �ɼ� ����
void Shop::setOption(string& myoption)
{
	option = myoption;
}

// int���� ���� ���� ������
bool Shop::operator==(int id) const
{
	return (this->itemID == id);
}

// string�� ���� ���� ������
bool Shop::operator==(string str) const
{
	return (this->shopdate == str);
}