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

	void inputClient();													// 고객 정보를 입력하고 clientlist에 삽입하는 함수
	Client* search(int ID);												// ID에 해당되는 고객 정보 불러옴
	void displayList();													// clientlist의 전체 고객 정보를 출력
	void addClient(Client* client);										// 고객 정보를 추가하는 함수
	int makeID();														// 고객 정보를 추가할 때 마다 ID를 자동으로 생성하는 함수
	void ChangeValue(int ID);											// ID에 해당되는 고객 정보를 수정하는 함수
	void deleteClient(int ID);											// ID에 해당되는 고객 정보를 삭제하는 함수
	void displayInfo(int id);											// ID에 해당되는 고객 정보를 출력하는 함수
	int countlist();													// clientlist에 있는 고객의 수를 세는 함수
	vector<string> parseCSV(istream&, char);							// 텍스트 파일에 어떻게 내용을 입력할 것인지 결정하는 함수
private:
	map<int, Client*> clientlist;										// 여러명의 고객을 관리하기 위해 맵으로 고객 리스트를 만듦
};

#endif			// __CLIENT_MANAGER__