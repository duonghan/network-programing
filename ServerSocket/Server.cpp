//#include <iostream>
//#include <stdio.h>
//#include <tchar.h>
//#include <winsock2.h>
//
//#pragma comment (lib,"ws2_32.lib")
//
//
//using namespace std;
//
//int _tmain(int argc, _TCHAR * argv[]) {
//	WSADATA SData;
//	int iResult = WSAStartup(0x2020, &SData);
//
//	if (iResult != 0)
//	{
//		cout << "Khong the khoi dong WinShock";
//		return 1;
//	}
//
//	cout << "KHOI TAO WINSHOCK THANH CONG: \n";
//	cout << "Phien ban: " << SData.wVersion << "\n";
//	cout << "Phien ban co the ho tro: " << SData.wHighVersion << "\n";
//	cout << "Ghi chu: " << SData.szDescription << "\n";
//	cout << "Thong tin cau hinh: " << SData.szSystemStatus << "\n";
//
//	
//
//	WSACleanup();
//	return 0;
//}
//
//int main() {
//	cout << "Hello World"<<endl;
//
//	system("pause");
//	return 0;
//}