#pragma once

#include "Defines.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class Client
{
public:
	Client(char *argv);
	~Client();
	void Send(char *sendbuf);
	void Receive(char *recvbuf);
	void SendFile(std::string filename);
	struct frame_t
	{
		char type;
		uint16_t len;
		char name[508];
	};
private:
	WSADATA wsaData;
	SOCKET ConnectSocket;
	struct addrinfo *result, *ptr, hints;
	int iResult;
	int recvbuflen;
};
