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

	void inputProduct();														// 상품 정보를 입력하여 productlist에 삽입하는 함수
	Product* search(int itemID);												// 상품 번호에 해당되는 상품 정보 불러옴
	void addProduct(Product* product);											// 상품 정보 추가하는 함수
	void displayList();															// productlist에 들어있는 전체 상품 정보를 출력하는 함수
	void deleteProduct(int ID);													// 상품 번호에 해당되는 상품 정보를 삭제하는 함수
	int makeID();																// 상품 정보를 추가할 때 마다 상품 번호를 자동으로 생성하는 함수
	void ChangeValue(int ID);													// 상품 번호에 해당되는 상품 정보를 수정하는 함수
	void displayInfo(int id);													// 상품 번호에 해당되는 상품 정보를 출력하는 함수
	int countlist();															// productlist에 들어있는 상품 정보이 수를 세는 함수
	void nameSearch();															// productlist에서 품목과 일치하는 상품 정보 출력하는 함수
	vector<string> parseCSV(istream&, char);									// 텍스트 파일에 어떻게 내용을 입력할 것인지 결정하는 함수
private:
	map<int, Product*> productlist;
};

#endif