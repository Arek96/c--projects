#include <iostream>
#include "Defines.h"
#include "CList.h"
#include <vector>
#include "Tester.h"
using namespace std;

double GetPerformanceCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	double freq = double(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart) / freq;
}

void main() {
	vector<point_t> points;
	//dodawanie elementów do listy kolekcji standardowej
	double startTime = GetPerformanceCounter();
	for (int i = 0; i < 1000; i++)
	{
		point_t p =
		{
			3 * i,
			3 * i + 1,
			3 * i + 2,
		};
		points.push_back(p);
	}
	double endTime = GetPerformanceCounter();
	cout << "Czas dodawania punktów do listy kolekcji standardowej wynosi: " << endTime - startTime << endl;
	endTime = startTime = 0;
	CList punkty;
	//dodawanie do listy jednkierunkowej
	startTime = GetPerformanceCounter();
		for (double i = 0; i < 1000; i++)
		{
			point_t p =
			{
				3 * i,
				3 * i + 1,
				3 * i + 2,
			};
			punkty.push_back(p);
		}
		endTime = GetPerformanceCounter();
		cout << "Czas dodawania punktów do listy jednokierunkowej wynosi: " << endTime - startTime << endl;
		//usuwanie z listy kolekcji standardowej
		endTime = startTime = 0;
		startTime = GetPerformanceCounter();
		for (int i = 0; i < 1000; i++) {
			points.pop_back();
		}
		endTime = GetPerformanceCounter();
		cout << "Czas odejmowania punktów z listy kolekcji standardowej wynosi: " << endTime - startTime << endl;
		endTime = startTime = 0;
		//usuwanie z listy jednokierunkowej
		startTime = GetPerformanceCounter();
		for (int i = 0; i < 1000; i++) {
			punkty.pop_back();
		}
		endTime = GetPerformanceCounter();
		cout << "Czas odejmowania punktów z listy jednokierunkowej wynosi: " << endTime - startTime << endl;
		startTime = endTime = 0;
		system("pause");

	}
