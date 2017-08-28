#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include <winsock2.h>
//#include "stdafx.h"

using namespace std;

#pragma comment (lib,"ws2_32.lib")

int main() {

	WSADATA SData;
	int iResult = WSAStartup(0x0202, &SData);
	if (iResult != 0) {
		cout << "KHONG THE KHOI DONG WINSOCK";
		return 1;
	}

	cout << "KHOI TAO SOCKET THANH CONG: \n";
	cout << "Phien ban: " << SData.wVersion << "\n";
	cout << "Phien ban co the ho tro: " << SData.wHighVersion << "\n";
	cout << "Ghi chu: " << SData.szDescription << "\n";
	cout << "Thong tin cau hinh: " << SData.szSystemStatus << "\n";

	WSACleanup();

	system("pause");
	return 0;
}