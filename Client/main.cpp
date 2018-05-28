#include "Client.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "Defines.h"

int main()
{
	char plik_tekst;
	do {
		setlocale(LC_ALL, "polish");
		std::string send = "";
		char recvbuf[DEFAULT_BUFLEN];
		char buf[DEFAULT_BUFLEN];
		char sprawdzenie;
		
		Client client("localhost");
		std::cout << "Tekst [t] czy plik [p]?" << std::endl;
		std::cin >> sprawdzenie;
		plik_tekst = sprawdzenie;
		if (sprawdzenie == 't') //przesy³anie tekstu
		{
			std::cout << "WprowadŸ tekst do przes³ania: ";
			std::cin >> send;
			memcpy(buf, send.c_str(), send.size() + 1);
			client.Send(buf);
			client.Receive(recvbuf);
		}
		else if (sprawdzenie == 'p') //przesy³anie pliku
		{
			std::cout << "Œcie¿ka do pliku: ";
			std::cin >> send;
			client.SendFile(send);
			client.Receive(buf);
		}
		std::cout << "Podaj poprawny znak." << std::endl;
	} 
	while (plik_tekst != 'p' && plik_tekst != 't');
	system("pause");
	return 0;
}