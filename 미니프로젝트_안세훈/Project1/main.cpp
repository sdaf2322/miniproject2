#include <iostream>
#include "client.h"
#include "clientmanager.h"
#include "product.h"
#include "productmanager.h"
#include "shop.h"
#include "shopmanager.h"

int main()
{
	ClientManager cm;
	ProductManager pm;
	ShopManager sm(cm, pm);
	int button1;
	int button2;
	char button3;
	char button4;
	int button5;

	while (1)
	{
		cout << "          상품 관리 프로그램" << endl;
		cout << "=======================================" << endl;
		cout << "           1. 고객 정보 관리" << endl;
		cout << "           2. 상품 정보 관리" << endl;
		cout << "           3. 쇼핑 정보 관리" << endl;
		cout << endl;
		cout << "      몇 번을 입력하시겠습니까?" << endl;
		cout << "=======================================" << endl;

		cin >> button1;																			// 1, 2, 3 중 숫자 선택
		while (1)
		{				
			if (button1 < 1 || button1 > 3)														// 1, 2, 3 이외의 숫자를 선택할 경우
			{
				cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
				cin >> button1;
			}
			else
				break;
		}
		
		switch (button1)																		
		{
		case(1): // 고객 정보 관리
			cout << "            고객 정보 관리" << endl;
			cout << endl;
			cout << "               1. 입력" << endl;
			cout << "               2. 조회" << endl;
			cout << "               3. 삭제" << endl;
			cout << "               4. 변경" << endl;
			cout << endl;
			cout << "      몇 번을 입력하시겠습니까?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;																		// 1, 2, 3, 4 중 숫자 선택
			while (1)
			{
				if (button2 < 1 || button2 > 4)													// 1, 2, 3, 4 이외의 숫자를 선택할 경우
				{
					cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1)	// 입력
			{
				while (1)
				{
					cout << "                 입력" << endl;
					cout << endl;
					cm.inputClient();
					cout << "입력을 종료하시겠습니까? Y/N" << endl;								// Y의 경우 입력종료, N의 경우 계속 입력
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')									// Y와 N 이외의 값을 입력한 경우
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> button3;
						}
						else
							break;
					}

					if (button3 == 'Y')
						break;
					else if (button3 == 'N')
					{
						cout << "=======================================" << endl; 
						continue;
					}
				}
			}
			else if (button2 == 2) // 조회
			{
				cout << "                 조회" << endl;
				cout << endl;
				cout << "          1. 고객 리스트" << endl;
				cout << "          2. 고객 정보" << endl;
				cout << endl;
				cout << "      몇 번을 입력하시겠습니까?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 2)
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)																// 1을 선택할 경우 고객 리스트로 들어감
				{
					cm.displayList();
				}
				else if (button5 == 2)															// 2를 선택할 경우 고객 정보로 들어감
				{
					int ID;
					cout << "고객ID를 입력하세요" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > cm.countlist())
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> ID;
						}
						else
							break;
					}
					cm.displayInfo(ID);
				}
			}
			else if (button2 == 3)	// 삭제
			{
				int ID;
				cout << "                 삭제" << endl;
				cout << endl;
				cout << "고객ID를 입력하세요" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > cm.countlist())
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> ID;
					}
					else
						break;
				}
				cm.deleteClient(ID);
				cout << "삭제가 완료되었습니다" << endl;
			}
			else if (button2 == 4)	// 변경
			{
				int ID;
				cout << "                 변경" << endl;
				cout << endl;
				cout << "고객ID를 입력하세요" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > cm.countlist())
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> ID;
					}
					else
						break;
				}
				cm.ChangeValue(ID);
			}

			break;

		case(2):	// 상품 정보 관리
			cout << "            상품 정보 관리" << endl;
			cout << endl;
			cout << "               1. 입력" << endl;
			cout << "               2. 조회" << endl;
			cout << "               3. 삭제" << endl;
			cout << "               4. 변경" << endl;
			cout << endl;
			cout << "      몇 번을 입력하시겠습니까?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;
			while (1)
			{
				if (button2 < 1 || button2 > 4)
				{
					cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1)	// 입력
			{
				while (1)
				{
					cout << "                 입력" << endl;
					cout << endl;
					pm.inputProduct();
					cout << "입력을 종료하시겠습니까? Y/N" << endl;
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> button3;
						}
						else
							break;
					}

					if (button3 == 'Y')
						break;
					else if (button3 == 'N')
					{
						cout << "=======================================" << endl; 
						continue;
					}
				}
			}
			else if (button2 == 2)	// 조회
			{
				cout << "                 조회" << endl;
				cout << endl;
				cout << "          1. 상품 리스트" << endl;
				cout << "          2. 상품 정보" << endl;
				cout << "          3. 품목 검색" << endl;
				cout << endl;
				cout << "      몇 번을 입력하시겠습니까?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 3)
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)	// 상품 리스트
				{
					pm.displayList();
				}
				else if (button5 == 2)	// 상품 정보
				{
					int ID;
					cout << "상품번호를 입력하세요" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > pm.countlist())
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> ID;
						}
						else
							break;
					}
					pm.displayInfo(ID);
				}
				else if (button5 == 3)	// 품목 검색
				{
					pm.nameSearch();
				}
			}
			else if (button2 == 3) // 삭제
			{
				int ID;
				cout << "                 삭제" << endl;
				cout << endl;
				cout << "상품번호를 입력하세요" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > pm.countlist())
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> ID;
					}
					else
						break;
				}
				pm.deleteProduct(ID);
				cout << "삭제가 완료되었습니다" << endl;
			}
			else if (button2 == 4) // 변경
			{
				int ID;
				cout << "                 변경" << endl;
				cout << endl;
				cout << "상품번호를 입력하세요" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > pm.countlist())
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> ID;
					}
					else
						break;
				}

				pm.ChangeValue(ID);
			}

			break;

		case(3): // 쇼핑 정보 관리
			cout << "            쇼핑 정보 관리" << endl;
			cout << endl;
			cout << "               1. 주문" << endl;
			cout << "               2. 조회" << endl;
			cout << "               3. 취소" << endl;

			cout << endl;
			cout << "      몇 번을 입력하시겠습니까?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;
			while (1)
			{
				if (button2 < 1 || button2 > 3)
				{
					cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1) // 주문
			{
				while (1)
				{
					cout << "                 주문" << endl;
					cout << endl;
					sm.inputShop();
					cout << "주문을 종료하시겠습니까? Y/N" << endl;
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> button3;
						}
						else
							break;
					}

					if (button3 == 'Y')
						break;
					else if (button3 == 'N')
					{
						cout << "=======================================" << endl; //39
						continue;
					}
				}
			}
			else if (button2 == 2) // 조회
			{
				int ID;
				cout << "                 조회" << endl;
				cout << endl;
				cout << "          1. 주문 리스트" << endl;
				cout << "          2. 주문 정보" << endl;
				cout << endl;
				cout << "      몇 번을 입력하시겠습니까?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 2)
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)	// 주문 리스트
				{
					sm.displayList(cm, pm);
				}
				else if (button5 == 2)	// 주문 정보
				{
					cout << "주문번호를 입력하세요" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > sm.countlist())
						{
							cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
							cin >> ID;
						}
						else
							break;
					}
					sm.displayInfo(cm, pm, ID);
				}
			}
			else if (button2 == 3) // 취소
			{
				int ID;
				cout << "                 취소" << endl;
				cout << endl;
				cout << "주문번호를 입력하세요" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > sm.countlist())
					{
						cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
						cin >> ID;
					}
					else
						break;
				}
				sm.deleteShop(ID);
				cout << "삭제가 완료되었습니다" << endl;
			}

			break;
		}

		cout << "계속 진행하시겠습니까? Y/N" << endl;
		cin >> button4;
		while (1)
		{
			if (button4 != 'Y' && button4 != 'N')
			{
				cout << "잘못된 값을 입력하였습니다. 다시 입력하세요." << endl;
				cin >> button4;
			}
			else
				break;
		}

		if (button4 == 'Y')
			continue;
		else if (button4 == 'N')
			break;
	}
}