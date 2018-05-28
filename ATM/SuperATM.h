#pragma once
#include "CashInATM.h"

class SuperATM : public CashInATM, ISTester {
public:
	SuperATM(int pin, int accountBalance);

	result_en rfidWithdraw();
    result_en withdraw(int amount);
    void serviceInfo(atmInfo &info, string &address);
};

