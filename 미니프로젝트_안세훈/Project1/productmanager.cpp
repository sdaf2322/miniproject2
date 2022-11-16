#include "productmanager.h"
#include "product.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

ProductManager::ProductManager()										
{
	ifstream file;																		// ���� �б� 
	file.open("productlist.txt");														// ���� ����
	if (!file.fail()) {																	// ���� ���⿡ �����Ѵٸ�
		while (!file.eof()) {															
			vector<string> row = parseCSV(file, ',');									// ������ ���� �� ���� ������ ���� 
			if (row.size()) {															
				int id = stoi(row[0]);													// string ������ row[0]���� ������ �̾� id�� ����
				Product* p = new Product(id, row[1], row[2], row[3], row[4]);		 
				productlist.insert({ id,p });											// ������ ������ productlist��� ����Ʈ�� ����
			}
		}
	}
	file.close(); // ���� �ݱ�
}

ProductManager::~ProductManager()									
{
	ofstream file;																		 // ���� ����
	file.open("productlist.txt");														 // ���� ����
	if (!file.fail()) {																	 // ���� ���⿡ �����Ѵٸ�
		for (const auto& v : productlist) { 											 // productlist���� ��ǰ ��ȣ(id)�� �ش�Ǵ� �����Ͱ��� ���Ͽ� ����
			Product* p = v.second;
			file << p->getID() << ", " << p->getProductName() << ", ";
			file << p->getPrice() << ", "; 
			file << p->getOption() << ", "; 
			file << p->getItem() << endl; 
		}
	}
	file.close(); // ���� �ݱ�
}

void ProductManager::inputProduct()												// ��ǰ ������ �Է��ϴ� �Լ�
{
	string productName, price, option, item;
	int itemID;

	cout << "��ǰ�� : "; cin >> productName;									// ��ǰ ���� �Է�
	cout << "���� : "; cin >> price;
	cout << "�ɼ� : "; cin.ignore();  getline(cin, option, '\n');				// ������ �����ؼ� �ޱ� ���� getline���� �Է�
	cout << "ǰ�� : "; cin >> item;
	
	itemID = makeID();															// �ý��� ������ ��ü������ id�� ����� ���̱� ������ makeID�� ���� ����
	Product* product = new Product(itemID, productName, price, option, item);
	productlist.insert({ itemID, product });									// productlist�� ID�� �ش�Ǵ� �� ������ ����
}

Product* ProductManager::search(int itemID)										// productlist���� ��ǰ ��ȣ�� �ش�Ǵ� �� ������ �ҷ����� �Լ�
{
	return productlist[itemID];
}

void ProductManager::addProduct(Product* product)								// �ܺο��� ��ǰ ������ �߰��ϱ� ���� ���� �Լ�
{
	productlist.insert({ product->getID(), product });
}

void ProductManager::displayList()												// productlist�� ����ִ� ��� ��ǰ ���� ����Ʈ�� ����ϴ� �Լ� 
{
	cout << endl << "  ID  |    ��ǰ��    |     ����     |      ǰ��       |     �ɼ�    " << endl;
	for (const auto& v : productlist) {
		Product* p = v.second;
		p->displayInfo();
	}
}  

void ProductManager::ChangeValue(int ID)										// ��ǰ ������ �����ϱ� ���� �Լ�
{
	string productName, price, item, option;
	Product* p = search(ID);

	if (p != nullptr) {
		cout << "��ǰ�� : "; cin >> productName;
		p->setProductName(productName);
		cout << "���� : "; cin >> price;
		p->setPrice(price);
		cout << "�ɼ� : "; getline(cin, option);								// ��ǰ �ɼ��� ������ �����Ͽ� �ޱ� ���� getline���� �Է�
		p->setItem(item);
		cout << "ǰ�� : "; cin >> item;
	}
}

int ProductManager::makeID()													// ��ǰ ������ �߰��� �� ���� ��ǰ ��ȣ�� �ڵ����� �����ϴ� �Լ�
{
	if (productlist.size() == 0)												// productlist�� ������ ������ 1�� ����
		return 1;
	else																		// ������ �����Ѵٸ�
	{
		auto element = productlist.end();
		int itemID = (--element)->first;
		return ++itemID;														// productlist�� ������ �������� ��ǰ ��ȣ�� ã�Ƽ� 1�� �����ְ� ����
	}
}

void ProductManager::displayInfo(int id)										// ��ǰ ��ȣ�� �ش��ϴ� ��ǰ ������ ����ϴ� �Լ�
{
	cout << endl << "  ID  |    ��ǰ��    |     ����     |      ǰ��       |     �ɼ�    " << endl;
	Product* product = search(id);
	product->displayInfo();
}

vector<string> ProductManager::parseCSV(istream& file, char delimiter)			// ','������ ���ڿ��� �߶� ���ͷ� ��ȯ�ϴ� �Լ�
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

void ProductManager::deleteProduct(int ID)											// ��ǰ ��ȣ�� �ش��ϴ� ��ǰ ������ �����ϴ� �Լ�
{
	productlist.erase(ID);
}

int ProductManager::countlist()														// productlist�� ����ִ� ��ǰ�� ������ ���� �Լ�
{
	int cnt = 0;
	for (const auto& v : productlist)
		cnt++;																		// productlist�� �ִ� ��ǰ ������ �ҷ��� �� ���� cnt���� 1�� ������Ŵ
	return cnt;
}

void ProductManager::nameSearch()													// ǰ���� ��ġ�ϴ� ��ǰ������ ����ϴ� �Լ�
{
	int found = 0;
	string item;
	string cmp_item;

	cout << "ã�� ���� ǰ���� �Է����ּ��� : ";
	cin >> item;																	// ǰ�� �Է�

	cout << endl << "  ID  |    ��ǰ��    |     ����     |      ǰ��       |     �ɼ�    " << endl;

	for (const auto v : productlist)
	{
		if (v.second != nullptr)
		{
			Product* p = v.second;
			cmp_item = p->getItem();												// productlist���� ID�� �ش��ϴ� ��ǰ �������� ǰ���� cmp_item�� ����

			if (item == cmp_item)													// �Է��� ǰ���� productlist�� �����Ѵٸ�
			{
				p->displayInfo();													// �ش� ǰ��� ��ġ�ϴ� ��ǰ ������ ���
				found = 1;
			}
		}
	}

	if (found == 0) {
		cout << "�������� �ʴ� ǰ���Դϴ�." << endl;								// �Է��� ǰ���� productlist�� ���� ��� ��°�
	}
}

