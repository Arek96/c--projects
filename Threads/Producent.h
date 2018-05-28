#pragma once
#include <cstdint>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;

class CProducent
{
private:
	vector<double> data;
	bool threadIsRunning;
	HANDLE dataMutex;
	HANDLE thread;
	static DWORD CALLBACK ThreadMain(void *CProducentPtr);
public:
	CProducent();																					//tworzy wıtek
	~CProducent();																					//zamyka wıtek
	void GetDataCopy(vector<double> &data);															//zwraca synchronicznie skopiowanı kolekcjê
};
