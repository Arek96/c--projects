#pragma warning(disable: 4996)

#include "Server.h"
#include <clocale>

int main()
{
	setlocale(LC_ALL, "polish");
	Serwer Ser;

	Ser.Accept();
	Ser.Echo();

	Ser.Shutdown();

	system("pause");
	return 0;
}