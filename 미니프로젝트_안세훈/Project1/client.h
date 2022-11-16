#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
using namespace std;

class Client
{
public:
	Client(int ID, string myname, string myphonenumber, string myemail, string myaddress);

	string getName() const;											// �� �̸� �����ϴ� �Լ�
	string getPhonenumber() const;									// �� ��ȭ��ȣ �����ϴ� �Լ�
	string getEmail() const;										// �� �̸��� �����ϴ� �Լ�
	string getAddress() const;										// �� �ּ� �����ϴ� �Լ�
	int getID() const;												// �� ID �����ϴ� �Լ�
	void setName(string& myname);									// �� �̸� �����ϴ� �Լ�
	void setPhonenumber(string& myphonenumber);						// �� ��ȭ��ȣ �����ϴ� �Լ�
	void setEmail(string& myemail);									// �� �̸��� �����ϴ� �Լ�
	void setAddress(string& address);								// �� �ּ� �����ϴ� �Լ�
	bool operator==(int) const;										// int���� ���� ���� ������
	bool operator==(string) const;									// string���� ���� ���� ������
	void displayInfo() const;										// �� ������ ����ϴ� �Լ�
private:
	int ID;
	string name;
	string phonenumber;
	string email;
	string address;
};

#endif