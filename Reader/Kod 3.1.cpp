#include <iostream>
#include <fstream>
#include <cstdint>

struct point_t { double x,y,z; };

int main()
{
	//otwieranie pliku tekstowego
	std::ofstream outFile("log.csv", std::ios::out);
	outFile << "linia1" << std::endl;
	outFile << "linia2" << std::endl;
	outFile.close();

	//tworzenie pliku binarnego
	std::ofstream outFile2("log.bin", std::ios::out | std::ios::binary);

	//tworzenie tablicy punkt�w
	point_t points[100];
	for (int i = 0; i < 100; i++)
	{
		points[i].x = (rand() % 100)/100.0;
		points[i].y = (rand() % 100)/100.0;
		points[i].z = (rand() % 100)/100.0;
	}
	uint32_t bytesToWrite = sizeof(points);
	outFile2.write((const char *)points, bytesToWrite);
	outFile2.close();

	//otwieranie pliku binarnego
	std::ifstream inFile("log.bin", std::ios::in | std::ios::binary);
	//obliczanie wielko�ci pliku
	
	inFile.seekg(0, inFile.end);		//ustawienie pozycji w pliku na jego koniec
	uint32_t bytes = inFile.tellg();	//pobranie d�ugo�ci pliku
	inFile.seekg(0, inFile.beg);		//ustawienie pozycji w pliku na jego pocz�tek

	//tworzenie buforu dla pliku
	uint8_t *buff = new uint8_t[bytes];

	//odczyt ca�ego pliku
	inFile.read((char *)buff, bytes);
	inFile.close();

	uint32_t pointsCount = bytes / sizeof(point_t);

	delete buff;
}