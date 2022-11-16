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

	void inputShop();																	// �ֹ� ������ �Է��ϰ� shoplist�� �����ϴ� �Լ�
	Shop* search(int shopID);															// �ֹ���ȣ�� �ش��ϴ� �ֹ� ������ �ҷ���
	void displayList(ClientManager cm, ProductManager pm);								// shoplist�� ����ִ� ��ü �ֹ� ������ ����ϴ� �Լ�
	void addShop(Shop* client);															// �ֹ� ������ �߰��ϴ� �Լ�
	void deleteShop(int ID);															// �ֹ���ȣ�� �ش�Ǵ� �ֹ� ������ �����ϴ� �Լ�
	int makeID();																		// �ֹ� ������ �Է��ϸ� �ڵ����� �ֹ���ȣ�� �����Ǵ� �Լ�
	void displayInfo(ClientManager cm, ProductManager pm, int id);						// �ֹ���ȣ�� �ش�Ǵ� �ֹ� ������ ����ϴ� �Լ�
	int getTotalPrice(ProductManager pm, int ID);										// ���ż����� ���� �Ѿ��� �����ϴ� �Լ�
	int countlist();																	// shoplist�� ����ִ� �ֹ��� ���� ���� �Լ�
	vector<string> parseCSV(istream&, char);											// �ؽ�Ʈ ���Ͽ� ��� ������ �Է��� ������ �����ϴ� �Լ�
private:
	map<int, Shop*> shoplist;															// �������� ���� �����ϱ� ���� ������ �� ����Ʈ�� ����
	ClientManager& cm;
	ProductManager& pm;
};
#endif
