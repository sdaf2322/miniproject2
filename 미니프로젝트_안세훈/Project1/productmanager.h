#ifndef __PRODUCT_MANAGER__
#define __PRODUCT_MANAGER__


#include <map>
#include "product.h"
#include<vector>

class ProductManager
{
public:
	ProductManager();
	~ProductManager();

	void inputProduct();														// ��ǰ ������ �Է��Ͽ� productlist�� �����ϴ� �Լ�
	Product* search(int itemID);												// ��ǰ ��ȣ�� �ش�Ǵ� ��ǰ ���� �ҷ���
	void addProduct(Product* product);											// ��ǰ ���� �߰��ϴ� �Լ�
	void displayList();															// productlist�� ����ִ� ��ü ��ǰ ������ ����ϴ� �Լ�
	void deleteProduct(int ID);													// ��ǰ ��ȣ�� �ش�Ǵ� ��ǰ ������ �����ϴ� �Լ�
	int makeID();																// ��ǰ ������ �߰��� �� ���� ��ǰ ��ȣ�� �ڵ����� �����ϴ� �Լ�
	void ChangeValue(int ID);													// ��ǰ ��ȣ�� �ش�Ǵ� ��ǰ ������ �����ϴ� �Լ�
	void displayInfo(int id);													// ��ǰ ��ȣ�� �ش�Ǵ� ��ǰ ������ ����ϴ� �Լ�
	int countlist();															// productlist�� ����ִ� ��ǰ ������ ���� ���� �Լ�
	void nameSearch();															// productlist���� ǰ��� ��ġ�ϴ� ��ǰ ���� ����ϴ� �Լ�
	vector<string> parseCSV(istream&, char);									// �ؽ�Ʈ ���Ͽ� ��� ������ �Է��� ������ �����ϴ� �Լ�
private:
	map<int, Product*> productlist;
};

#endif