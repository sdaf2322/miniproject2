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
	ifstream file;																					// 파일 읽기
	file.open("shoplist.txt");																		// 파일 열기
	if (!file.fail()) {																				// 파일 열기에 성공한다면
		while (!file.eof()) {		
			vector<string> row = parseCSV(file, ',');												// 파일이 끝날 때 까지 내용을 읽음 
			if (row.size()) {
				int id = stoi(row[0]);																// string 형태의 row[0]에서 정수를 뽑아 id에 저장
				Shop* shop = new Shop(id, stoi(row[1]), stoi(row[2]), row[3], row[4], row[5]);
				shoplist.insert({ id, shop });                                                      // 파일의 내용을 shoplist라는 리스트에 삽입
			}
		}
	}
	file.close(); // 파일 닫기
}

ShopManager::~ShopManager()
{
	ofstream file;																					// 파일 저장
	file.open("shoplist.txt");																		// 파일 열기
	if (!file.fail()) {																				// 파일 열기에 성공한다면
		for (const auto& v : shoplist) {															// shoplist에서 id에 해당되는 데이터값을 파일에 저장
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
	file.close(); // 파일 닫기 
}

void ShopManager::inputShop()														// 주문 정보를 입력하는 함수
{
	string shopdate, quantity, price, name, productName, option;
	int shopID, clientID, itemID;
	cout << "주문자ID : "; cin >> clientID;											// 주문 정보 입력
	cout << "상품번호 : "; cin >> itemID; 
	cout << "주문날짜 : "; cin >> shopdate;
	cout << "주문수량 : "; cin >> quantity;
	cout << "옵션 : "; cin >> option;

	shopID = makeID();																// 시스템 내에서 자체적으로 id를 만드는 것이기 때문에 makeID로 따로 구현
	Shop *shop = new Shop(shopID, clientID, itemID, shopdate, quantity, option); 
	shoplist.insert({ shopID, shop });												// shoplist에 주문 번호(ID)에 해당되는 주문 정보를 삽입
}

Shop* ShopManager::search(int shopID)												// shoplist에서 주문 번호에 해당되는 주문 정보를 불러오는 함수
{
	return shoplist[shopID];
}

void ShopManager::displayList(ClientManager cm, ProductManager pm)					// shoplist에서 주문 정보가 들어있는 전체 리스트를 출력하는 함수
{
	cout << endl << "  ID  |    주문자    |   구매제품   |     옵션     |   주문수량   |   주문날짜   |   상품번호   |     가격    " << endl;
	
	for(auto it : shoplist)															// for문을 돌 때 마다 shoplist에 있는 주문 정보들을 하나씩 불러옴
	{
		Shop* item = it.second;
		Client* client = cm.search(item->getClientID());
		Product* product = pm.search(item->getItemID());

		cout << setw(5) << setfill('0') << right << item->getShopID() << " | " << left;			// 주문 정보 출력
		cout << setw(12) << setfill(' ') << client->getName() << " | "; 
		cout << setw(12) << product->getProductName() << " | "; 
		cout << setw(12) << item->getOption() << " | "; 
		cout << setw(12) << item->getQuantity() << " | ";
		cout << setw(12) << item->getShopdate() << " | "; 
		cout << setw(12) << item->getItemID() << " | "; 
		cout << getTotalPrice(pm, item->getShopID()) << endl; 
	}
}

void ShopManager::displayInfo(ClientManager cm, ProductManager pm, int id)			// shoplist에서 주문 번호에 해당하는 주문 정보 출력
{	
	cout << endl << "  ID  |    주문자    |   구매제품   |     옵션     |   주문수량   |   주문날짜   |   상품번호   |     가격    " << endl;
	Shop* item = search(id);														// 주문 번호에 해당되는 주문 정보를 item에 저장
	if (item != nullptr) {															// 주문 정보가 존재한다면
		Client* client = cm.search(item->getClientID()); 
		Product* product = pm.search(item->getItemID()); 

		cout << setw(5) << setfill('0') << right << id << " | " << left;			// 주문 정보 출력
		cout << setw(12) << setfill(' ') << client->getName() << " | "; 
		cout << setw(12) << product->getProductName() << " | "; 
		cout << setw(12) << item->getOption() << " | "; 
		cout << setw(12) << item->getQuantity() << " | "; 
		cout << setw(12) << item->getShopdate() << " | "; 
		cout << setw(12) << item->getItemID() << " | "; 
		cout << getTotalPrice(pm, id) << endl; 
	}
}

void ShopManager::addShop(Shop* shop)												// 외부에서 새로운 주문 정보를 추가할 때 사용하는 함수
{
	shoplist.insert({ shop->getShopID(), shop });
}

int ShopManager::makeID()															// 고객에 대한 정보를 추가할 시 주문 번호를 자동으로 생성하는 함수
{
	if (shoplist.size() == 0)														// shoplist에 내용이 없다면 1을 반환
		return 1;
	else																			// shoplist에 내용이 존재한다면 
	{
		auto element = shoplist.end();
		int itemID = (--element)->first;
		return ++itemID;															// shoplist의 마지막 데이터의 주문 정보를 찾아서 1을 더해주고 리턴
	}
}

int ShopManager::getTotalPrice(ProductManager pm, int ID)							// 주무 수량에 따른 총액을 리턴하는 함수
{
	int total = stoi(search(ID)->getQuantity()) * stoi(pm.search(search(ID)->getItemID())->getPrice());		// string에서 정수를 추출하기 위해 stoi를 사용
	return total;
}

void ShopManager::deleteShop(int ID)												// 주문 번호에 해당하는 주문 정보 삭제하는 함수
{
	shoplist.erase(ID);
}

vector<string> ShopManager::parseCSV(istream& file, char delimiter)					// ','단위로 문자열을 잘라 벡터로 반환하는 함수
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

int ShopManager::countlist()														// shoplist에 있는 주문의 수를 세는 함수
{
	int cnt = 0;
	for (const auto& v : shoplist)
		cnt++;																		// shoplist에 있는 주문 정보를 불러올 때 마다 cnt값을 1씩 증가시킴
	return cnt;
}