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
	ifstream file;                                                               // ���� �б� 
	file.open("clientlist.txt");                                                 // ���� ����
	if (!file.fail()) {                                                          // ���� ���⿡ �����Ѵٸ�
		while (!file.eof()) { 
			vector<string> row = parseCSV(file, ',');                            // ������ ���� �� ���� ������ ���� 
			if (row.size()) {
				int id = stoi(row[0]);                                           // string ������ row[0]���� ������ �̾� id�� ����
				Client* c = new Client(id, row[1], row[2], row[3], row[4]); 
				clientlist.insert({ id, c });                                    // ������ ������ clientlist��� ����Ʈ�� ����
			}
		}
	}
	file.close(); // ���� �ݱ�
}

ClientManager::~ClientManager()
{
	ofstream file;                                                              // ���� ����
	file.open("clientlist.txt");											    // ���� ����
	if (!file.fail()) {															// ���� ���⿡ �����Ѵٸ�
		for (const auto& v : clientlist) {										// clientlist���� id�� �ش�Ǵ� �����Ͱ��� ���Ͽ� ����
			Client* c = v.second;
			file << c->getID() << ", " << c->getName() << ", ";
			file << c->getPhonenumber() << ", ";
			file << c->getAddress() << ", ";
			file << c->getEmail() << endl;
		}
	}

	file.close(); // ���� �ݱ� 
}

void ClientManager::inputClient()												// �� ������ �Է��ϴ� �Լ�
{
	string name, phonenumber, email, address;

	cout << "�̸� : "; cin >> name;												// �� ���� �Է�
	cout << "��ȭ��ȣ : "; cin >> phonenumber;
	cout << "�̸��� : "; cin >> email;
	cout << "�ּ� : "; cin >> address;

	int ID = makeID();															// �ý��� ������ ��ü������ id�� ����� ���̱� ������ makeID�� ���� ����
	Client* client = new Client(ID, name, phonenumber, email, address);
	clientlist.insert({ ID, client });											// clientlist�� ID�� �ش�Ǵ� �� ������ ����
}

Client* ClientManager::search(int ID)											// clientlist���� ID�� �ش�Ǵ� �� ������ �ҷ����� �Լ�
{
	auto it = clientlist.find(ID);												// clientlist���� ID�� �ش�Ǵ� �� ������ ����ִ� ��ġ�� ã��
	return (it != clientlist.end()) ? clientlist[ID] : nullptr;					// �� ������ ����ִ� ��ġ�� ã�´ٸ� ����
}

void ClientManager::displayList()												// clientlist���� �� ������ ����ִ� ��ü ����Ʈ�� ����ϴ� �Լ�
{
	cout << endl << "  ID  |     �̸�     |   ��ȭ��ȣ    |     �̸���     |      �ּ�    " << endl;
	for (const auto& v : clientlist) {
		Client* c = v.second;
		c->displayInfo();														// displayInfo() �Լ��� �� ������ ����ϴ� �Լ�
	}
}

void ClientManager::addClient(Client* client)									// �ܺο��� ���ο� ���� ������ �߰��� �� ����ϴ� �Լ�
{
	clientlist.insert({ client->getID(), client });
}

void ClientManager::ChangeValue(int ID)											// �� ������ �����ϴ� �Լ�
{
	string name, phonenumber, email, address;
	Client* c = search(ID);														// clientlist���� ID�� �ش��ϴ� �� ������ ã�Ƽ� ������ ����

	if (c != nullptr) {
		cout << "�̸� : "; cin >> name;
		c->setName(name);
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		c->setPhonenumber(phonenumber);
		cout << "�̸��� : "; cin >> email;
		c->setEmail(email);
		cout << "�ּ� : "; cin >> address;
		c->setAddress(address);
	}
}

int ClientManager::makeID()											// ���� ���� ������ �߰��� �� ID�� �ڵ����� �����ϴ� �Լ�
{
	if (clientlist.size() == 0)										// clientlist�� ������ ���ٸ� 1�� ��ȯ
		return 1;
	else															// clientlist�� ������ �����Ѵٸ� 
	{
		auto element = clientlist.end();							// clientlist�� ������ �κ��� ����Ű�� ���� ��ġ�� ���� 
		int ID = (--element)->first;								// clientlist�� ������ �κ��� element�� ���� ��ġ�̹Ƿ� 1�� ���� �ش�Ǵ� ID���� ã��
		return ++ID;												// ������ �κ��� ID�� 1�� ���ϰ� ����
	}
}

void ClientManager::deleteClient(int ID)							// �� ������ �����ϴ� �Լ�
{
	clientlist.erase(ID);
}

void ClientManager::displayInfo(int id)								// ID�� �ش��ϴ� �� ������ ����ϴ� �Լ�
{
	cout << endl << "  ID  |     �̸�     |   ��ȭ��ȣ    |     �̸���     |      �ּ�    " << endl;
	Client* client = search(id);
	client->displayInfo();
}

vector<string> ClientManager::parseCSV(istream& file, char delimiter)			// ','������ ���ڿ��� �߶� ���ͷ� ��ȯ�ϴ� �Լ�
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

int ClientManager::countlist()													// clientlist�� �ִ� ���� ���� ���� �Լ�
{
	int cnt = 0;
	for (const auto& v : clientlist)
		cnt++;																	// clientlist�� �ִ� �� ������ �ҷ��� �� ���� cnt���� 1�� ������Ŵ
	return cnt;
}