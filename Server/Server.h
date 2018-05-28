#pragma once
#pragma warning(disable: 4996)
#undef UNICODE

#pragma once

#include "Defines.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <iostream>
#include <fstream>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32.lib")

class Serwer
{
public:

	Serwer();
	~Serwer();
	void Accept();
	void Echo();
	void Shutdown();

private:

	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket,
		ClientSocket;

	struct addrinfo *result,
		hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen;
};
