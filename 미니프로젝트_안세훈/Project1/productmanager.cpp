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
	ifstream file;																		// 파일 읽기 
	file.open("productlist.txt");														// 파일 열기
	if (!file.fail()) {																	// 파일 열기에 성공한다면
		while (!file.eof()) {															
			vector<string> row = parseCSV(file, ',');									// 파일이 끝날 때 까지 내용을 읽음 
			if (row.size()) {															
				int id = stoi(row[0]);													// string 형태의 row[0]에서 정수를 뽑아 id에 저장
				Product* p = new Product(id, row[1], row[2], row[3], row[4]);		 
				productlist.insert({ id,p });											// 파일의 내용을 productlist라는 리스트에 삽입
			}
		}
	}
	file.close(); // 파일 닫기
}

ProductManager::~ProductManager()									
{
	ofstream file;																		 // 파일 저장
	file.open("productlist.txt");														 // 파일 열기
	if (!file.fail()) {																	 // 파일 열기에 성공한다면
		for (const auto& v : productlist) { 											 // productlist에서 상품 번호(id)에 해당되는 데이터값을 파일에 저장
			Product* p = v.second;
			file << p->getID() << ", " << p->getProductName() << ", ";
			file << p->getPrice() << ", "; 
			file << p->getOption() << ", "; 
			file << p->getItem() << endl; 
		}
	}
	file.close(); // 파일 닫기
}

void ProductManager::inputProduct()												// 상품 정보를 입력하는 함수
{
	string productName, price, option, item;
	int itemID;

	cout << "상품명 : "; cin >> productName;									// 상품 정보 입력
	cout << "가격 : "; cin >> price;
	cout << "옵션 : "; cin.ignore();  getline(cin, option, '\n');				// 공백을 포함해서 받기 위해 getline으로 입력
	cout << "품목 : "; cin >> item;
	
	itemID = makeID();															// 시스템 내에서 자체적으로 id를 만드는 것이기 때문에 makeID로 따로 구현
	Product* product = new Product(itemID, productName, price, option, item);
	productlist.insert({ itemID, product });									// productlist에 ID에 해당되는 고객 정보를 삽입
}

Product* ProductManager::search(int itemID)										// productlist에서 상품 번호에 해당되는 고객 정보를 불러오는 함수
{
	return productlist[itemID];
}

void ProductManager::addProduct(Product* product)								// 외부에서 상품 정보를 추가하기 위해 만든 함수
{
	productlist.insert({ product->getID(), product });
}

void ProductManager::displayList()												// productlist에 들어있는 모든 상품 정보 리스트를 출력하는 함수 
{
	cout << endl << "  ID  |    제품명    |     가격     |      품목       |     옵션    " << endl;
	for (const auto& v : productlist) {
		Product* p = v.second;
		p->displayInfo();
	}
}  

void ProductManager::ChangeValue(int ID)										// 상품 정보를 수정하기 위한 함수
{
	string productName, price, item, option;
	Product* p = search(ID);

	if (p != nullptr) {
		cout << "상품명 : "; cin >> productName;
		p->setProductName(productName);
		cout << "가격 : "; cin >> price;
		p->setPrice(price);
		cout << "옵션 : "; getline(cin, option);								// 상품 옵션을 공백을 포함하여 받기 위해 getline으로 입력
		p->setItem(item);
		cout << "품목 : "; cin >> item;
	}
}

int ProductManager::makeID()													// 상품 정보를 추가할 때 마다 상품 번호를 자동으로 생성하는 함수
{
	if (productlist.size() == 0)												// productlist에 내용이 없으면 1을 리턴
		return 1;
	else																		// 내용이 존재한다면
	{
		auto element = productlist.end();
		int itemID = (--element)->first;
		return ++itemID;														// productlist의 마지막 데이터의 상품 번호를 찾아서 1을 더해주고 리턴
	}
}

void ProductManager::displayInfo(int id)										// 상품 번호에 해당하는 상품 정보를 출력하는 함수
{
	cout << endl << "  ID  |    제품명    |     가격     |      품목       |     옵션    " << endl;
	Product* product = search(id);
	product->displayInfo();
}

vector<string> ProductManager::parseCSV(istream& file, char delimiter)			// ','단위로 문자열을 잘라 벡터로 반환하는 함수
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

void ProductManager::deleteProduct(int ID)											// 상품 번호에 해당하는 상품 정보를 삭제하는 함수
{
	productlist.erase(ID);
}

int ProductManager::countlist()														// productlist에 들어있는 상품의 개수를 세는 함수
{
	int cnt = 0;
	for (const auto& v : productlist)
		cnt++;																		// productlist에 있는 상품 정보를 불러올 때 마다 cnt값을 1씩 증가시킴
	return cnt;
}

void ProductManager::nameSearch()													// 품목이 일치하는 상품정보를 출력하는 함수
{
	int found = 0;
	string item;
	string cmp_item;

	cout << "찾고 싶은 품목을 입력해주세요 : ";
	cin >> item;																	// 품목 입력

	cout << endl << "  ID  |    제품명    |     가격     |      품목       |     옵션    " << endl;

	for (const auto v : productlist)
	{
		if (v.second != nullptr)
		{
			Product* p = v.second;
			cmp_item = p->getItem();												// productlist에서 ID에 해당하는 상품 정보에서 품목을 cmp_item에 저장

			if (item == cmp_item)													// 입력한 품목이 productlist에 존재한다면
			{
				p->displayInfo();													// 해당 품목과 일치하는 상품 정보를 출력
				found = 1;
			}
		}
	}

	if (found == 0) {
		cout << "존재하지 않는 품목입니다." << endl;								// 입력한 품목이 productlist에 없는 경우 출력값
	}
}

