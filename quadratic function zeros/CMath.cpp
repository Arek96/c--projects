
#include "CMath.h"
#include <iostream>
#include "stdafx.h"
#include "Defines.h"
#include <math.h>
CMath::CMath()
{

};
void CMath::Add(const double &a, const double &b)  //definicja metody dodawania
{
	wynik = a + b;

}
void CMath::Sub(const double &a, const double &b) //definicja metody odejmowania
{
	wynik = a - b;

}
void CMath::Mul(const double &a, const double &b) // definicja metody mno¿enia
{
	wynik = a*b;

}
result_en CMath::Div(const double &a, const double &b) //definicja metody dzielenia
{
	if (b == 0)
	{
		wynik = 0;
		return res_error;
	}
	else
	{
		wynik = a / b;
		return res_ok;
	}
}



double CMath::GetValue() const //definicja metody zwracania wyniku
{
	return  wynik;
}
result_en CMath::SquareFunc(const double &a, const double &b, const double &c, double &x1, double &x2) const // definicja metody obliczania miejsc zerowych funkcji kwadratowej
{
	double delta = pow(b, 2) - (4 * a*c);
	
	if (delta > 0) {
		x1 = ((-1)*b - sqrt(delta)) / (2 * a);
		x2 = ((-1)*b + sqrt(delta)) / (2 * a);
		return res_1_result;
	}
	else if (delta == 0) {
		x1 = (-b) / (2 * a);
		x1 = x2;
		return res_2_results;
	}
	else if (delta < 0) {
		
		return res_error;
	}

}





