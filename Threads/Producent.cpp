
#include"Producent.h"

CProducent::CProducent()																			//tworzy w¹tek
{
	threadIsRunning = true;																			//ustawienie flagi threadIsRunning na prawdê
	dataMutex = CreateMutex(NULL, false, NULL);
	thread = CreateThread(NULL, 0, ThreadMain, (LPVOID)this, 0, 0);
	SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
}
CProducent::~CProducent()																			//zamyka w¹tek
{
	threadIsRunning = false;																		//ustawienie flagi threadIsRunning na fa³sz
	WaitForSingleObject(thread, INFINITE);															//czekanie na zakoñczenie w¹tku thread
	CloseHandle(thread);
	CloseHandle(dataMutex);
}
void CProducent::GetDataCopy(vector<double> &data)													//zwraca synchronicznie skopiowan¹ kolekcjê
{
	WaitForSingleObject(dataMutex, INFINITE);
	data = this->data;																				//przpisanie tego z obiektu do data
	ReleaseMutex(dataMutex);
}
DWORD CProducent::ThreadMain(void *CProducentPtr)
{
	srand(time(0));
	CProducent *producent = (CProducent *)CProducentPtr;
	while (producent->threadIsRunning)																//kiedy threadIsRunning jest prawdziwe
	{
		WaitForSingleObject(producent->dataMutex, INFINITE);
		producent->data.push_back((rand() % 1000));													//wrzucenie liczby pseudolosowej z przedzia³u <0;999> na koniec wektora wewn¹trz
		ReleaseMutex(producent->dataMutex);
		Sleep(10);																					//poczekanie, ¿eby program nie lagowa³
	}
	return 0;
}