#include <iostream>
#include <cstdint>
#include <windows.h>
#include <vector>


using namespace std;


double GetPerformanceCounter()
{
    LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	double freq = double(li.QuadPart)/1000.0;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart)/freq;
}

//struktura punktu
struct point_t { int x,y,z; };

int main()
{
	double startTime = GetPerformanceCounter();
	vector<point_t> points;
	//dodawanie elementów do listy
	for (int i = 0; i < 10000; i++)
	{
		point_t p = 
		{
			3*i,
			3*i + 1,
			3*i + 2,
		};
		points.push_back(p);
	}
	point_t sum = { 0, 0, 0 };
	//sumowanie elemntów z listy
	for(vector<point_t>::iterator it = points.begin(); it != points.end(); it++)
	{
		sum.x += it->x;
		sum.y += it->y;
		sum.z += it->z;
	}
	//wyœwietlanie 100 elementu
	point_t element = points[100];
	cout <<  "100-ny element: " << element.x << "," << element.y << "," << element.z << endl;
	double endTime = GetPerformanceCounter();
	cout << "Operacja trwala: " << endTime - startTime << " ms" << endl;
	system("pause");
	return 0;
}