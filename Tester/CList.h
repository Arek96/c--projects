#pragma once
#define USER_NAME    "Arkadiusz"         //Proszê wpisaæ swoje Imiê
#define USER_SURNAME "Osoba"     //Proszê wpisaæ swoje Nazwizko
#define USER_GROUP   4 				//Proszê wpisac numer grupy
#include "Tester.h"

class CList : public Tester
{
private:
    list_el *first;
	mutable size_t count;
public:
    CList();
    ~CList();
    void push_back(const point_t &p);
    result_en pop_back();
    result_en insert(size_t kr, const point_t &p);
    result_en find( const point_t &p, size_t &kr) const;
    result_en get(size_t kr, point_t &p) const;
    size_t size() const;
};