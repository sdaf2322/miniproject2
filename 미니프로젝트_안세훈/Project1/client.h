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

	string getName() const;											// 고객 이름 리턴하는 함수
	string getPhonenumber() const;									// 고객 전화번호 리턴하는 함수
	string getEmail() const;										// 고객 이메일 리턴하는 함수
	string getAddress() const;										// 고객 주소 리턴하는 함수
	int getID() const;												// 고객 ID 리턴하는 함수
	void setName(string& myname);									// 고객 이름 수정하는 함수
	void setPhonenumber(string& myphonenumber);						// 고객 전화번호 수정하는 함수
	void setEmail(string& myemail);									// 고객 이메일 수정하는 함수
	void setAddress(string& address);								// 고객 주소 수정하는 함수
	bool operator==(int) const;										// int형에 대한 대입 연산자
	bool operator==(string) const;									// string형에 대한 대입 연산자
	void displayInfo() const;										// 고객 정보를 출력하는 함수
private:
	int ID;
	string name;
	string phonenumber;
	string email;
	string address;
};

#endif