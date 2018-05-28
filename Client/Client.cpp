#include "Client.h"

using namespace std;
Client::Client(char *argv)
{
	ConnectSocket = INVALID_SOCKET;

	result = NULL;
	ptr = NULL;

	recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);

	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(argv, DEFAULT_PORT, &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET)
		{
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();

		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\n");
		WSACleanup();
	}
}

Client::~Client()
{
	closesocket(ConnectSocket);
	WSACleanup();
}

void Client::Send(char *sendbuf)
{
	frame_t ramka;
	ramka.type = 0;
	ramka.len = (int)strlen(sendbuf) + 1 + sizeof(frame_t);

	char * buffer = new char[(int)strlen(sendbuf) + 1 + sizeof(frame_t)];

	memcpy(buffer, &ramka, sizeof(frame_t));

	memcpy(buffer + sizeof(frame_t), sendbuf, (int)strlen(sendbuf) + 1);

	iResult = send(ConnectSocket, buffer, ramka.len, 0);
	if (iResult == SOCKET_ERROR)
	{
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
	}

	printf("Bytes Sent: %ld\n", iResult);

	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
	}
}

void Client::Receive(char *recvbuf)
{
	do {
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());
		
	} while (iResult > 0);
	
}

void Client::SendFile(string filename)
{
	ifstream plik;

	plik.open(filename.c_str(), ios::in | ios::binary);

	plik.seekg(0, plik.end);
	int length = plik.tellg();
	plik.seekg(0, plik.beg);

	char *bu = new char[length + sizeof(frame_t)];

	cout << "Reading " << length << " bytes... " << endl;

	frame_t ramka;
	ramka.type = 1;
	ramka.len = length + sizeof(frame_t);

	memcpy(&ramka.name, filename.c_str(), filename.size() + 1);
	memcpy(bu, &ramka, sizeof(frame_t));

	plik.read(bu + sizeof(frame_t), length);


	iResult = send(ConnectSocket, bu, ramka.len, 0);
	if (iResult == SOCKET_ERROR)
	{
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
	}

	printf("Bytes Sent: %ld\n", iResult);
}