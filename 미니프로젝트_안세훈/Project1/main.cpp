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
		cout << "          ��ǰ ���� ���α׷�" << endl;
		cout << "=======================================" << endl;
		cout << "           1. �� ���� ����" << endl;
		cout << "           2. ��ǰ ���� ����" << endl;
		cout << "           3. ���� ���� ����" << endl;
		cout << endl;
		cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
		cout << "=======================================" << endl;

		cin >> button1;																			// 1, 2, 3 �� ���� ����
		while (1)
		{				
			if (button1 < 1 || button1 > 3)														// 1, 2, 3 �̿��� ���ڸ� ������ ���
			{
				cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
				cin >> button1;
			}
			else
				break;
		}
		
		switch (button1)																		
		{
		case(1): // �� ���� ����
			cout << "            �� ���� ����" << endl;
			cout << endl;
			cout << "               1. �Է�" << endl;
			cout << "               2. ��ȸ" << endl;
			cout << "               3. ����" << endl;
			cout << "               4. ����" << endl;
			cout << endl;
			cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;																		// 1, 2, 3, 4 �� ���� ����
			while (1)
			{
				if (button2 < 1 || button2 > 4)													// 1, 2, 3, 4 �̿��� ���ڸ� ������ ���
				{
					cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1)	// �Է�
			{
				while (1)
				{
					cout << "                 �Է�" << endl;
					cout << endl;
					cm.inputClient();
					cout << "�Է��� �����Ͻðڽ��ϱ�? Y/N" << endl;								// Y�� ��� �Է�����, N�� ��� ��� �Է�
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')									// Y�� N �̿��� ���� �Է��� ���
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
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
			else if (button2 == 2) // ��ȸ
			{
				cout << "                 ��ȸ" << endl;
				cout << endl;
				cout << "          1. �� ����Ʈ" << endl;
				cout << "          2. �� ����" << endl;
				cout << endl;
				cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 2)
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)																// 1�� ������ ��� �� ����Ʈ�� ��
				{
					cm.displayList();
				}
				else if (button5 == 2)															// 2�� ������ ��� �� ������ ��
				{
					int ID;
					cout << "��ID�� �Է��ϼ���" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > cm.countlist())
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
							cin >> ID;
						}
						else
							break;
					}
					cm.displayInfo(ID);
				}
			}
			else if (button2 == 3)	// ����
			{
				int ID;
				cout << "                 ����" << endl;
				cout << endl;
				cout << "��ID�� �Է��ϼ���" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > cm.countlist())
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> ID;
					}
					else
						break;
				}
				cm.deleteClient(ID);
				cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
			}
			else if (button2 == 4)	// ����
			{
				int ID;
				cout << "                 ����" << endl;
				cout << endl;
				cout << "��ID�� �Է��ϼ���" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > cm.countlist())
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> ID;
					}
					else
						break;
				}
				cm.ChangeValue(ID);
			}

			break;

		case(2):	// ��ǰ ���� ����
			cout << "            ��ǰ ���� ����" << endl;
			cout << endl;
			cout << "               1. �Է�" << endl;
			cout << "               2. ��ȸ" << endl;
			cout << "               3. ����" << endl;
			cout << "               4. ����" << endl;
			cout << endl;
			cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;
			while (1)
			{
				if (button2 < 1 || button2 > 4)
				{
					cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1)	// �Է�
			{
				while (1)
				{
					cout << "                 �Է�" << endl;
					cout << endl;
					pm.inputProduct();
					cout << "�Է��� �����Ͻðڽ��ϱ�? Y/N" << endl;
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
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
			else if (button2 == 2)	// ��ȸ
			{
				cout << "                 ��ȸ" << endl;
				cout << endl;
				cout << "          1. ��ǰ ����Ʈ" << endl;
				cout << "          2. ��ǰ ����" << endl;
				cout << "          3. ǰ�� �˻�" << endl;
				cout << endl;
				cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 3)
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)	// ��ǰ ����Ʈ
				{
					pm.displayList();
				}
				else if (button5 == 2)	// ��ǰ ����
				{
					int ID;
					cout << "��ǰ��ȣ�� �Է��ϼ���" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > pm.countlist())
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
							cin >> ID;
						}
						else
							break;
					}
					pm.displayInfo(ID);
				}
				else if (button5 == 3)	// ǰ�� �˻�
				{
					pm.nameSearch();
				}
			}
			else if (button2 == 3) // ����
			{
				int ID;
				cout << "                 ����" << endl;
				cout << endl;
				cout << "��ǰ��ȣ�� �Է��ϼ���" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > pm.countlist())
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> ID;
					}
					else
						break;
				}
				pm.deleteProduct(ID);
				cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
			}
			else if (button2 == 4) // ����
			{
				int ID;
				cout << "                 ����" << endl;
				cout << endl;
				cout << "��ǰ��ȣ�� �Է��ϼ���" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > pm.countlist())
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> ID;
					}
					else
						break;
				}

				pm.ChangeValue(ID);
			}

			break;

		case(3): // ���� ���� ����
			cout << "            ���� ���� ����" << endl;
			cout << endl;
			cout << "               1. �ֹ�" << endl;
			cout << "               2. ��ȸ" << endl;
			cout << "               3. ���" << endl;

			cout << endl;
			cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
			cout << "=======================================" << endl;

			cin >> button2;
			while (1)
			{
				if (button2 < 1 || button2 > 3)
				{
					cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
					cin >> button2;
				}
				else
					break;
			}

			if (button2 == 1) // �ֹ�
			{
				while (1)
				{
					cout << "                 �ֹ�" << endl;
					cout << endl;
					sm.inputShop();
					cout << "�ֹ��� �����Ͻðڽ��ϱ�? Y/N" << endl;
					cin >> button3;
					while (1)
					{
						if (button3 != 'Y' && button3 != 'N')
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
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
			else if (button2 == 2) // ��ȸ
			{
				int ID;
				cout << "                 ��ȸ" << endl;
				cout << endl;
				cout << "          1. �ֹ� ����Ʈ" << endl;
				cout << "          2. �ֹ� ����" << endl;
				cout << endl;
				cout << "      �� ���� �Է��Ͻðڽ��ϱ�?" << endl;
				cout << "=======================================" << endl;

				cin >> button5;
				while (1)
				{
					if (button5 < 1 || button5 > 2)
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> button5;
					}
					else
						break;
				}

				if (button5 == 1)	// �ֹ� ����Ʈ
				{
					sm.displayList(cm, pm);
				}
				else if (button5 == 2)	// �ֹ� ����
				{
					cout << "�ֹ���ȣ�� �Է��ϼ���" << endl;
					cin >> ID;
					while (1)
					{
						if (ID < 1 || ID > sm.countlist())
						{
							cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
							cin >> ID;
						}
						else
							break;
					}
					sm.displayInfo(cm, pm, ID);
				}
			}
			else if (button2 == 3) // ���
			{
				int ID;
				cout << "                 ���" << endl;
				cout << endl;
				cout << "�ֹ���ȣ�� �Է��ϼ���" << endl;
				cin >> ID;
				while (1)
				{
					if (ID < 1 || ID > sm.countlist())
					{
						cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
						cin >> ID;
					}
					else
						break;
				}
				sm.deleteShop(ID);
				cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
			}

			break;
		}

		cout << "��� �����Ͻðڽ��ϱ�? Y/N" << endl;
		cin >> button4;
		while (1)
		{
			if (button4 != 'Y' && button4 != 'N')
			{
				cout << "�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���." << endl;
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