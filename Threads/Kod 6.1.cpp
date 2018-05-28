#include <iostream>
#include <cstdint>
#include <Windows.h>

bool threadIsRunning = true;
HANDLE dataMutex = NULL;
double shared_data = 0;

DWORD CALLBACK Thread(void *p_ptr)
{
	//Bufor odebray w w¹tku
	uint8_t *dataToSend = (uint8_t *)p_ptr;
	
	for (int i = 0; i < 10; i++)
	{
		shared_data += dataToSend[i]/10.0;
	}
	
	Sleep(100);
	while(threadIsRunning)
	{
		//Synchronizacja udostêpnionych danych
		WaitForSingleObject(dataMutex, INFINITE);
		shared_data = (rand() % 1000)/100.0 - 5.0;
		ReleaseMutex(dataMutex);

		Sleep(100);
	}

	return 0;
}

int main()
{
	//Tworzenie obiektow do synchronizacji
	dataMutex = CreateMutex(NULL, false, NULL);

	//Bufor przesy³any do w¹tku
	uint8_t *dataToSend = new uint8_t[10];
	for (int i = 0; i < 10; i++)
	{
		dataToSend[i] = i;
	}

	//Tworzenie w¹tku i przesy³anie adresu pamiêci z buforem danych
	HANDLE thread = CreateThread(NULL, 0, Thread, (LPVOID)dataToSend, 0, 0);
	SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
	Sleep(50);

	//10 sekund pêtli g³ównej
	for (int i = 0; i < 100; i++)
	{
		//Synchronizacja odbierania danych
		WaitForSingleObject(dataMutex, INFINITE);
		std::cout << shared_data << std::endl;
		ReleaseMutex(dataMutex);
		Sleep(100);
	}

	//Zakoñczenie w¹tku Thread
	threadIsRunning = false;
	//Czekanie na zakoñczenie w¹tku Thread
	WaitForSingleObject(thread, INFINITE);
	system("pause");

	//Zamkniêcie wszystkich uchwytów
	CloseHandle(thread);
	CloseHandle(dataMutex);
}