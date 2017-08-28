#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <winsock2.h>

#pragma comment (lib,"ws2_32.lib")


using namespace std;

int main() {

	WSADATA wasData;
	WORD wVersion = MAKEWORD(2, 2);

	if (WSAStartup(wVersion, &wasData))
	{
		cout << "Version is not supported" << endl;
	}

	SOCKET server;
	server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5500);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(server,(sockaddr *)&serverAddr, sizeof(serverAddr)))
	{
		cout << "Error! Cannot bind this address." << endl;
		system("pause");
		return 0;
	}

	cout << "Server started!" << endl;

	sockaddr_in clientAddr;
	char buff[BUFF_SIZE];
	int ret, clientAddrLen = sizeof(clientAddr);

	while (true)
	{
		ret = recvfrom(server, buff, BUFF_SIZE, 0, (sockaddr *)&clientAddr, &clientAddrLen);

		if (ret == SOCKET_ERROR)
		{
			cout << "Error: " << WSAGetLastError();
		} 
		else
		{
			cout << "Receive from client " << inet_ntoa(clientAddr.sin_addr) << " : " 
			<< ntohs(clientAddr.sin_port) << " " << buff << endl;

		}

		ret = sendto(server, buff, ret, 0, (SOCKADDR *)&clientAddr, sizeof(clientAddr));

		if (ret == SOCKET_ERROR)
		{
			cout << "Error: " << WSAGetLastError();

		}
	}

	closesocket(server);
	WSACleanup();

	return 0;
}