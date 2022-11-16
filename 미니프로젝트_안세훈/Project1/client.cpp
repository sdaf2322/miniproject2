#include <iostream>
#include "client.h"
#include <iomanip>
using namespace std;

Client::Client(int ID, string myname, string myphonenumber, string myemail, string myaddress)
	: ID(ID), name(myname), phonenumber(myphonenumber), email(myemail), address(myaddress)
{

}

// �� �̸� ����
string Client::getName() const
{
	return name;
}

// �� ��ȭ��ȣ ����
string Client::getPhonenumber() const
{
	return phonenumber;
}

// �� �̸��� ����
string Client::getEmail() const
{
	return email;
}

// �� �ּ� ����
string Client::getAddress() const
{
	return address;
}

// �� �̸� ����
void Client::setName(string& myname)
{
	name = myname;
}

// �� ��ȭ��ȣ ����
void Client::setPhonenumber(string& myphonenumber)
{
	phonenumber = myphonenumber;
}

// �� �̸��� ����
void Client::setEmail(string& myemail)
{
	email = myemail;
}

// �� �ּ� ����
void Client::setAddress(string& myaddress)
{
	address = myaddress;
}

// �� ID ����
int Client::getID() const
{
	return ID;
}

// �� ���� ���
void Client::displayInfo() const
{
	cout << setw(5) << setfill('0') << right << ID << " | " << left;
	cout << setw(12) << setfill(' ') << name << " | ";
	cout << setw(12) << phonenumber << " | ";
	cout << setw(12) << email << " | ";
	cout << address << endl;
}

// int�� �ش�Ǵ� ���� ������
bool Client::operator==(int id) const
{
	return (this->ID == id);
}

// string�� �ش�Ǵ� ���� ������
bool Client::operator==(string str) const
{
	return (this->name == str);
}