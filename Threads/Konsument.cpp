#include "Producent.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	CProducent producent;																			//zrobienie obiektu producent
	vector<double> data;																			//wektor do ktorego bedziemy wrzucac skopiowane z producenta rzeczy
	unsigned char liczba = 0;																			//znak sczytywany z klawiatury
	while (liczba != 27)																				//jeœli jest ró¿ny od 27 - esc; enter to 13
	{
		producent.GetDataCopy(data);																//skopiowanie danych z producenta
		double suma = 0;																			//suma - potrzebn1a do liczenia sredniej
		for (int i = 0; i < data.size(); i++)														//petla od i=0 do konca wektora
		{
			suma += data.at(i);																		//zliczanie sumy
		}
		if (data.size() != 0)																		//jeœli rozmiar jest ró¿ny od zera to
		{
			cout << "Srednia: " << suma / data.size() << "\n";										//wyœwietl srendnia
			cout << "Ilosc elementow: " << data.size() << "\n";										//wyœwietl ile jest elementow
			cout << "Ostatni element: " << data[data.size() - 1] << "\n";								//wyœwietl ostatni element
		}
		do {
			std::cout << "wciscinj esc aby zamknaæ watek lub enter aby zobaczyæ wyniki";
			liczba = _getch();	
			
		}while (liczba != 13 && liczba != 27);																			//skocz do cofnij

		
	}
	return 0;
}