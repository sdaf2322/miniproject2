#include "shopmanager.h"
#include "shop.h"
#include "client.h"
#include "product.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

ShopManager::ShopManager(ClientManager& cm, ProductManager& pm) : cm(cm), pm(pm) 
{
	ifstream file;																					// ���� �б�
	file.open("shoplist.txt");																		// ���� ����
	if (!file.fail()) {																				// ���� ���⿡ �����Ѵٸ�
		while (!file.eof()) {		
			vector<string> row = parseCSV(file, ',');												// ������ ���� �� ���� ������ ���� 
			if (row.size()) {
				int id = stoi(row[0]);																// string ������ row[0]���� ������ �̾� id�� ����
				Shop* shop = new Shop(id, stoi(row[1]), stoi(row[2]), row[3], row[4], row[5]);
				shoplist.insert({ id, shop });                                                      // ������ ������ shoplist��� ����Ʈ�� ����
			}
		}
	}
	file.close(); // ���� �ݱ�
}

ShopManager::~ShopManager()
{
	ofstream file;																					// ���� ����
	file.open("shoplist.txt");																		// ���� ����
	if (!file.fail()) {																				// ���� ���⿡ �����Ѵٸ�
		for (const auto& v : shoplist) {															// shoplist���� id�� �ش�Ǵ� �����Ͱ��� ���Ͽ� ����
			Shop* item = v.second; 
			Client* client = cm.search(item->getClientID());
			Product* product = pm.search(item->getItemID());
			file << item->getShopID() << ", ";
			file << item->getClientID() << ", ";
			file << item->getItemID() << ", ";
			file << item->getShopdate() << ", ";
			file << item->getQuantity() << ", ";
			file << item->getOption() << endl;
		}
	}
	file.close(); // ���� �ݱ� 
}

void ShopManager::inputShop()														// �ֹ� ������ �Է��ϴ� �Լ�
{
	string shopdate, quantity, price, name, productName, option;
	int shopID, clientID, itemID;
	cout << "�ֹ���ID : "; cin >> clientID;											// �ֹ� ���� �Է�
	cout << "��ǰ��ȣ : "; cin >> itemID; 
	cout << "�ֹ���¥ : "; cin >> shopdate;
	cout << "�ֹ����� : "; cin >> quantity;
	cout << "�ɼ� : "; cin >> option;

	shopID = makeID();																// �ý��� ������ ��ü������ id�� ����� ���̱� ������ makeID�� ���� ����
	Shop *shop = new Shop(shopID, clientID, itemID, shopdate, quantity, option); 
	shoplist.insert({ shopID, shop });												// shoplist�� �ֹ� ��ȣ(ID)�� �ش�Ǵ� �ֹ� ������ ����
}

Shop* ShopManager::search(int shopID)												// shoplist���� �ֹ� ��ȣ�� �ش�Ǵ� �ֹ� ������ �ҷ����� �Լ�
{
	return shoplist[shopID];
}

void ShopManager::displayList(ClientManager cm, ProductManager pm)					// shoplist���� �ֹ� ������ ����ִ� ��ü ����Ʈ�� ����ϴ� �Լ�
{
	cout << endl << "  ID  |    �ֹ���    |   ������ǰ   |     �ɼ�     |   �ֹ�����   |   �ֹ���¥   |   ��ǰ��ȣ   |     ����    " << endl;
	
	for(auto it : shoplist)															// for���� �� �� ���� shoplist�� �ִ� �ֹ� �������� �ϳ��� �ҷ���
	{
		Shop* item = it.second;
		Client* client = cm.search(item->getClientID());
		Product* product = pm.search(item->getItemID());

		cout << setw(5) << setfill('0') << right << item->getShopID() << " | " << left;			// �ֹ� ���� ���
		cout << setw(12) << setfill(' ') << client->getName() << " | "; 
		cout << setw(12) << product->getProductName() << " | "; 
		cout << setw(12) << item->getOption() << " | "; 
		cout << setw(12) << item->getQuantity() << " | ";
		cout << setw(12) << item->getShopdate() << " | "; 
		cout << setw(12) << item->getItemID() << " | "; 
		cout << getTotalPrice(pm, item->getShopID()) << endl; 
	}
}

void ShopManager::displayInfo(ClientManager cm, ProductManager pm, int id)			// shoplist���� �ֹ� ��ȣ�� �ش��ϴ� �ֹ� ���� ���
{	
	cout << endl << "  ID  |    �ֹ���    |   ������ǰ   |     �ɼ�     |   �ֹ�����   |   �ֹ���¥   |   ��ǰ��ȣ   |     ����    " << endl;
	Shop* item = search(id);														// �ֹ� ��ȣ�� �ش�Ǵ� �ֹ� ������ item�� ����
	if (item != nullptr) {															// �ֹ� ������ �����Ѵٸ�
		Client* client = cm.search(item->getClientID()); 
		Product* product = pm.search(item->getItemID()); 

		cout << setw(5) << setfill('0') << right << id << " | " << left;			// �ֹ� ���� ���
		cout << setw(12) << setfill(' ') << client->getName() << " | "; 
		cout << setw(12) << product->getProductName() << " | "; 
		cout << setw(12) << item->getOption() << " | "; 
		cout << setw(12) << item->getQuantity() << " | "; 
		cout << setw(12) << item->getShopdate() << " | "; 
		cout << setw(12) << item->getItemID() << " | "; 
		cout << getTotalPrice(pm, id) << endl; 
	}
}

void ShopManager::addShop(Shop* shop)												// �ܺο��� ���ο� �ֹ� ������ �߰��� �� ����ϴ� �Լ�
{
	shoplist.insert({ shop->getShopID(), shop });
}

int ShopManager::makeID()															// ���� ���� ������ �߰��� �� �ֹ� ��ȣ�� �ڵ����� �����ϴ� �Լ�
{
	if (shoplist.size() == 0)														// shoplist�� ������ ���ٸ� 1�� ��ȯ
		return 1;
	else																			// shoplist�� ������ �����Ѵٸ� 
	{
		auto element = shoplist.end();
		int itemID = (--element)->first;
		return ++itemID;															// shoplist�� ������ �������� �ֹ� ������ ã�Ƽ� 1�� �����ְ� ����
	}
}

int ShopManager::getTotalPrice(ProductManager pm, int ID)							// �ֹ� ������ ���� �Ѿ��� �����ϴ� �Լ�
{
	int total = stoi(search(ID)->getQuantity()) * stoi(pm.search(search(ID)->getItemID())->getPrice());		// string���� ������ �����ϱ� ���� stoi�� ���
	return total;
}

void ShopManager::deleteShop(int ID)												// �ֹ� ��ȣ�� �ش��ϴ� �ֹ� ���� �����ϴ� �Լ�
{
	shoplist.erase(ID);
}

vector<string> ShopManager::parseCSV(istream& file, char delimiter)					// ','������ ���ڿ��� �߶� ���ͷ� ��ȯ�ϴ� �Լ�
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

int ShopManager::countlist()														// shoplist�� �ִ� �ֹ��� ���� ���� �Լ�
{
	int cnt = 0;
	for (const auto& v : shoplist)
		cnt++;																		// shoplist�� �ִ� �ֹ� ������ �ҷ��� �� ���� cnt���� 1�� ������Ŵ
	return cnt;
}