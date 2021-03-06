// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
#include <string>

using namespace std;

int main(int agrc, char** grv)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	InetPton(AF_INET, _T("127.0.0.1"), &addr.sin_addr.s_addr); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	cout << "Connected to server!" << endl;

	int count = 0;
	std::string buffer = "";
	buffer +=std::string(grv[1]);
	while (1)
	{
		
		send(server, buffer.c_str(), sizeof(buffer), 0);
		cout << "Message sent!" << count << endl;
		Sleep(1000);
		count++;
	}




	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
}

