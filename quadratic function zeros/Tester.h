/**
 * \brief Nag³ówek klasy testuj¹cej
 * \file Tester.h
 * \author Pawel Iwaneczko
 * \copyright Copyright 2017 HTeam. All rights reserved. 
 */
#pragma once
#ifndef IG_TESTER_H
#define IG_TESTER_H
#include <cstdint>
#include "Defines.h"

class Tester
{
public:
    virtual void Add(const double &a, const double &b) = 0;
    virtual void Sub(const double &a, const double &b) = 0;
    virtual void Mul(const double &a, const double &b) = 0;
    virtual result_en Div(const double &a, const double &b) = 0;

    virtual double GetValue() const = 0;

    virtual result_en SquareFunc(const double &a, const double &b, const double &c, double &x1, double &x2) const = 0;
};


#pragma region Statistics
#ifndef TESTER
extern "C" {
    __declspec(dllexport) Tester *TesterConstructor();
    __declspec(dllexport) size_t TesterDestructor(void *);
    __declspec(dllexport) size_t TesterUserName(char *username, size_t usernameSize, uint8_t *group);
}

#include <Windows.h>
#include <thread>
#include <mutex>
#include <map>
#include <string>
namespace statistics {
    using namespace std;
    class Stats {
    private:
        bool initialized;
        mutex locker;
        thread::id id;
        map<void *, size_t> stats;
    public:
        Stats();
        ~Stats();
        size_t Count() const;
        void AddPtr(void* ptr, size_t count);
        void RemovePtr(void* ptr);
    };
};

void* operator new (size_t count);
void operator delete (void* ptr);
void operator delete[](void* ptr);
#endif /* !TESTER */
#pragma endregion
#endif /* IG_TESTER_H */