#pragma once
#include "ATM.h"

class RegularATM : public ATM, IRTester {
public:
	RegularATM(int pin, int accountBalance);

    result_en checkBalance(int& balance);
    void serviceInfo(atmInfo &info, string &address);
};

