#include "clientmanager.h"
#include "client.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

ClientManager::ClientManager()
{
	ifstream file;                                                               // 파일 읽기 
	file.open("clientlist.txt");                                                 // 파일 열기
	if (!file.fail()) {                                                          // 파일 열기에 성공한다면
		while (!file.eof()) { 
			vector<string> row = parseCSV(file, ',');                            // 파일이 끝날 때 까지 내용을 읽음 
			if (row.size()) {
				int id = stoi(row[0]);                                           // string 형태의 row[0]에서 정수를 뽑아 id에 저장
				Client* c = new Client(id, row[1], row[2], row[3], row[4]); 
				clientlist.insert({ id, c });                                    // 파일의 내용을 clientlist라는 리스트에 삽입
			}
		}
	}
	file.close(); // 파일 닫기
}

ClientManager::~ClientManager()
{
	ofstream file;                                                              // 파일 저장
	file.open("clientlist.txt");											    // 파일 열기
	if (!file.fail()) {															// 파일 열기에 성공한다면
		for (const auto& v : clientlist) {										// clientlist에서 id에 해당되는 데이터값을 파일에 저장
			Client* c = v.second;
			file << c->getID() << ", " << c->getName() << ", ";
			file << c->getPhonenumber() << ", ";
			file << c->getAddress() << ", ";
			file << c->getEmail() << endl;
		}
	}

	file.close(); // 파일 닫기 
}

void ClientManager::inputClient()												// 고객 정보를 입력하는 함수
{
	string name, phonenumber, email, address;

	cout << "이름 : "; cin >> name;												// 고객 정보 입력
	cout << "전화번호 : "; cin >> phonenumber;
	cout << "이메일 : "; cin >> email;
	cout << "주소 : "; cin >> address;

	int ID = makeID();															// 시스템 내에서 자체적으로 id를 만드는 것이기 때문에 makeID로 따로 구현
	Client* client = new Client(ID, name, phonenumber, email, address);
	clientlist.insert({ ID, client });											// clientlist에 ID에 해당되는 고객 정보를 삽입
}

Client* ClientManager::search(int ID)											// clientlist에서 ID에 해당되는 고객 정보를 불러오는 함수
{
	auto it = clientlist.find(ID);												// clientlist에서 ID에 해당되는 고객 정보가 들어있는 위치를 찾음
	return (it != clientlist.end()) ? clientlist[ID] : nullptr;					// 고객 정보가 들어있는 위치를 찾는다면 리턴
}

void ClientManager::displayList()												// clientlist에서 고객 정보가 들어있는 전체 리스트를 출력하는 함수
{
	cout << endl << "  ID  |     이름     |   전화번호    |     이메일     |      주소    " << endl;
	for (const auto& v : clientlist) {
		Client* c = v.second;
		c->displayInfo();														// displayInfo() 함수는 고객 정보를 출력하는 함수
	}
}

void ClientManager::addClient(Client* client)									// 외부에서 새로운 고객의 정보를 추가할 때 사용하는 함수
{
	clientlist.insert({ client->getID(), client });
}

void ClientManager::ChangeValue(int ID)											// 고객 정보를 수정하는 함수
{
	string name, phonenumber, email, address;
	Client* c = search(ID);														// clientlist에서 ID에 해당하는 고객 정보를 찾아서 정보를 수정

	if (c != nullptr) {
		cout << "이름 : "; cin >> name;
		c->setName(name);
		cout << "전화번호 : "; cin >> phonenumber;
		c->setPhonenumber(phonenumber);
		cout << "이메일 : "; cin >> email;
		c->setEmail(email);
		cout << "주소 : "; cin >> address;
		c->setAddress(address);
	}
}

int ClientManager::makeID()											// 고객에 대한 정보를 추가할 시 ID를 자동으로 생성하는 함수
{
	if (clientlist.size() == 0)										// clientlist에 내용이 없다면 1을 반환
		return 1;
	else															// clientlist에 내용이 존재한다면 
	{
		auto element = clientlist.end();							// clientlist의 마지막 부분이 가리키는 다음 위치를 저장 
		int ID = (--element)->first;								// clientlist의 마지막 부분은 element의 이전 위치이므로 1을 빼고 해당되는 ID값을 찾음
		return ++ID;												// 마지막 부분의 ID에 1을 더하고 리턴
	}
}

void ClientManager::deleteClient(int ID)							// 고객 정보를 삭제하는 함수
{
	clientlist.erase(ID);
}

void ClientManager::displayInfo(int id)								// ID에 해당하는 고객 정보를 출력하는 함수
{
	cout << endl << "  ID  |     이름     |   전화번호    |     이메일     |      주소    " << endl;
	Client* client = search(id);
	client->displayInfo();
}

vector<string> ClientManager::parseCSV(istream& file, char delimiter)			// ','단위로 문자열을 잘라 벡터로 반환하는 함수
{
	stringstream ss;
	vector<string> row;
	string t = " \n\r\t";

	while (!file.eof()) {
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n') {
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t)); 
			s.erase(s.find_last_not_of(t) + 1);
			row.push_back(s);
			ss.str("");
			if (c != delimiter) break;
		}
		else {
			ss << c;
		}
	}
	return row;
}

int ClientManager::countlist()													// clientlist에 있는 고객의 수를 세는 함수
{
	int cnt = 0;
	for (const auto& v : clientlist)
		cnt++;																	// clientlist에 있는 고객 정보를 불러올 때 마다 cnt값을 1씩 증가시킴
	return cnt;
}