#pragma once
#define USER_NAME    "Imiê"         //Proszê wpisaæ swoje Imiê
#define USER_SURNAME "Nazwisko"     //Proszê wpisaæ swoje Nazwizko
#define USER_GROUP   0 				//Proszê wpisac numer grupy
#include "Tester.h"

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