#ifndef __CLIENT_MANAGER__
#define __CLIENT_MANAGER__

#include <map>
#include "client.h"
#include<vector>

using namespace std;

class ClientManager
{
public:
	ClientManager();
	~ClientManager();

	void inputClient();													// �� ������ �Է��ϰ� clientlist�� �����ϴ� �Լ�
	Client* search(int ID);												// ID�� �ش�Ǵ� �� ���� �ҷ���
	void displayList();													// clientlist�� ��ü �� ������ ���
	void addClient(Client* client);										// �� ������ �߰��ϴ� �Լ�
	int makeID();														// �� ������ �߰��� �� ���� ID�� �ڵ����� �����ϴ� �Լ�
	void ChangeValue(int ID);											// ID�� �ش�Ǵ� �� ������ �����ϴ� �Լ�
	void deleteClient(int ID);											// ID�� �ش�Ǵ� �� ������ �����ϴ� �Լ�
	void displayInfo(int id);											// ID�� �ش�Ǵ� �� ������ ����ϴ� �Լ�
	int countlist();													// clientlist�� �ִ� ���� ���� ���� �Լ�
	vector<string> parseCSV(istream&, char);							// �ؽ�Ʈ ���Ͽ� ��� ������ �Է��� ������ �����ϴ� �Լ�
private:
	map<int, Client*> clientlist;										// �������� ���� �����ϱ� ���� ������ �� ����Ʈ�� ����
};

#endif			// __CLIENT_MANAGER__