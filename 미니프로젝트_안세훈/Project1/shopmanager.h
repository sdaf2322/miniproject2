#ifndef __SHOP_MANAGER__
#define __SHOP_MANAGER__


#include <map>
#include "shop.h"
#include "clientmanager.h"
#include "productmanager.h"
#include <vector>

using namespace std;

class ShopManager
{
public:
	ShopManager(ClientManager&, ProductManager&);
	~ShopManager();

	void inputShop();																	// 주문 정보를 입력하고 shoplist에 삽입하는 함수
	Shop* search(int shopID);															// 주문번호에 해당하는 주문 정보를 불러옴
	void displayList(ClientManager cm, ProductManager pm);								// shoplist에 들어있는 전체 주문 정보를 출력하는 함수
	void addShop(Shop* client);															// 주문 정보를 추가하는 함수
	void deleteShop(int ID);															// 주문번호에 해당되는 주문 정보를 삭제하는 함수
	int makeID();																		// 주문 정보를 입력하면 자동으로 주문번호가 생성되는 함수
	void displayInfo(ClientManager cm, ProductManager pm, int id);						// 주문번호에 해당되는 주문 정보를 출력하는 함수
	int getTotalPrice(ProductManager pm, int ID);										// 구매수량에 따른 총액을 리턴하는 함수
	int countlist();																	// shoplist에 들어있는 주문의 수를 세는 함수
	vector<string> parseCSV(istream&, char);											// 텍스트 파일에 어떻게 내용을 입력할 것인지 결정하는 함수
private:
	map<int, Shop*> shoplist;															// 여러명의 고객을 관리하기 위해 맵으로 고객 리스트를 만듦
	ClientManager& cm;
	ProductManager& pm;
};
#endif
