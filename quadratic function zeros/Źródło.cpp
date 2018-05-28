// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "CMath.h"



int main()
{
	std::cout << "Proszê podaæ zmienna a:" << std::endl;
	double a = 0;
	std::cin >> a; //wczytanie zmiennej a
	std::cout << "Prosze podac zminna b: " << std::endl;
	double b = 0;
	std::cin >> b; //wczytanie zmiennej b
	std::cout << "Prosze podac zmienna c: " << std::endl;
	double c = 0;
	std::cin >> c; //wczytanie zmiennej c
	double x1 = 0, x2 = 0;
	CMath c1; // utworzenie obiektu c1 klasy CMath
	c1.SquareFunc(a, b, c, x1, x2); 

	std::cout << "Wartosci pierwiastków s¹ nastêpuj¹ce:" << x1 << "\n" << x2 << std::endl;
	system("pause");


	return 0;
}

