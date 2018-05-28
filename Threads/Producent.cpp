
#include"Producent.h"

CProducent::CProducent()																			//tworzy w�tek
{
	threadIsRunning = true;																			//ustawienie flagi threadIsRunning na prawd�
	dataMutex = CreateMutex(NULL, false, NULL);
	thread = CreateThread(NULL, 0, ThreadMain, (LPVOID)this, 0, 0);
	SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
}
CProducent::~CProducent()																			//zamyka w�tek
{
	threadIsRunning = false;																		//ustawienie flagi threadIsRunning na fa�sz
	WaitForSingleObject(thread, INFINITE);															//czekanie na zako�czenie w�tku thread
	CloseHandle(thread);
	CloseHandle(dataMutex);
}
void CProducent::GetDataCopy(vector<double> &data)													//zwraca synchronicznie skopiowan� kolekcj�
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
		producent->data.push_back((rand() % 1000));													//wrzucenie liczby pseudolosowej z przedzia�u <0;999> na koniec wektora wewn�trz
		ReleaseMutex(producent->dataMutex);
		Sleep(10);																					//poczekanie, �eby program nie lagowa�
	}
	return 0;
}