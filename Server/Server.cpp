#include "Server.h"

Serwer::Serwer()
{
	ListenSocket = INVALID_SOCKET;																							
	ClientSocket = INVALID_SOCKET;

	result = NULL;

	recvbuflen = DEFAULT_BUFLEN;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);																		
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);																

	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);										

	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
	}


	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);													

	if (iResult == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
	}

	freeaddrinfo(result);
}

Serwer::~Serwer()
{
	closesocket(ListenSocket);
	closesocket(ClientSocket);
	WSACleanup();
}

void Serwer::Accept()
{
	iResult = listen(ListenSocket, SOMAXCONN);																				

	printf("listening... \n");

	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
	}

	ClientSocket = accept(ListenSocket, NULL, NULL);																		
	if (ClientSocket == INVALID_SOCKET)
	{
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
	}

	printf("accepted \n");

}
struct frame_t
{
	char type;
	uint16_t len;
	char name[508];
};




void Serwer::Echo()
{
	bool interacja1 = true;
	bool rodzaj_ramki;
	printf("echoing... \n");

	do {
		frame_t ramka;


		memcpy(&ramka, recvbuf, sizeof(frame_t));

		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);

		rodzaj_ramki = ramka.type;

		int downloaded = iResult;

		if (iResult > 0)
		{

			if (rodzaj_ramki == 0)
			{
				printf("Byty otrzymane: %d\n", iResult);

				iSendResult = send(ClientSocket, recvbuf, iResult, 0);

				if (iSendResult == SOCKET_ERROR)
				{
					printf("Wysy³anie zakoñczone b³edem: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}

				printf("Byty wys³ane: %d\n", iSendResult);
				if (interacja1 == false)
				{
					std::cout << "Otrzymano tekst:" << std::endl;
					for (int i = 0; recvbuf[i] != NULL; i++)
					{
						std::cout << recvbuf[i];
					}
					std::cout << std::endl << std::endl;
				}
				interacja1 = false;
			}
			else if (rodzaj_ramki == 1)
			{
				std::ofstream plikk("zapis.bin", std::ios::out | std::ios::binary);

				std::cout << std::endl << "Otrzymano plik" << std::endl;

				printf("Byty otrzymane: %d\n", iResult);

				plikk.write(recvbuf, ramka.len - sizeof(frame_t));

				iSendResult = send(ClientSocket, recvbuf, iResult, 0);

				if (iSendResult == SOCKET_ERROR)
				{
					printf("Wysy³anie zakoñczone b³edem: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					break;
				}

				printf("Byty wys³ane: %d\n", iSendResult);

				std::cout << "Saving " << ramka.len - sizeof(frame_t) << " bytes (" << "zapis.bin" << ")" << std::endl;

			}
		}
		else
			if (iResult == 0)
			{
				printf("Connection closing...\n");
			}
			else
			{
				printf("recv failed with error: %d\n", WSAGetLastError());
			}
	} while (iResult > 0);
}

void Serwer::Shutdown()
{
	printf("shutting down\n");
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
	}
}