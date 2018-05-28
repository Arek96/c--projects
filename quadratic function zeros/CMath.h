#pragma once
#define USER_NAME    "NAME"         //Proszê wpisaæ swoje Imiê
#define USER_SURNAME "SURNAME"     //Proszê wpisaæ swoje Nazwizko
#define USER_GROUP  1 				//Proszê wpisac numer grupy
#include "Tester.h"
#include <iostream>
#include "stdafx.h"

class CMath : public Tester
{

private:
	double wynik;
public:
	CMath();

	void Add(const double &a, const double &b);
	void Sub(const double &a, const double &b);
	void Mul(const double &a, const double &b);
	result_en Div(const double &a, const double &b);

	double GetValue() const;

	result_en SquareFunc(const double &a, const double &b, const double &c, double &x1, double &x2) const;
};