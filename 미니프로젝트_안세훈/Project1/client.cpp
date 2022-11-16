#include <iostream>
#include "client.h"
#include <iomanip>
using namespace std;

Client::Client(int ID, string myname, string myphonenumber, string myemail, string myaddress)
	: ID(ID), name(myname), phonenumber(myphonenumber), email(myemail), address(myaddress)
{

}

// 고객 이름 리턴
string Client::getName() const
{
	return name;
}

// 고객 전화번호 리턴
string Client::getPhonenumber() const
{
	return phonenumber;
}

// 고객 이메일 리턴
string Client::getEmail() const
{
	return email;
}

// 고객 주소 리턴
string Client::getAddress() const
{
	return address;
}

// 고객 이름 수정
void Client::setName(string& myname)
{
	name = myname;
}

// 고객 전화번호 수정
void Client::setPhonenumber(string& myphonenumber)
{
	phonenumber = myphonenumber;
}

// 고객 이메일 수정
void Client::setEmail(string& myemail)
{
	email = myemail;
}

// 고객 주소 수정
void Client::setAddress(string& myaddress)
{
	address = myaddress;
}

// 고객 ID 리턴
int Client::getID() const
{
	return ID;
}

// 고객 정보 출력
void Client::displayInfo() const
{
	cout << setw(5) << setfill('0') << right << ID << " | " << left;
	cout << setw(12) << setfill(' ') << name << " | ";
	cout << setw(12) << phonenumber << " | ";
	cout << setw(12) << email << " | ";
	cout << address << endl;
}

// int에 해당되는 대입 연산자
bool Client::operator==(int id) const
{
	return (this->ID == id);
}

// string에 해당되는 대입 연산자
bool Client::operator==(string str) const
{
	return (this->name == str);
}