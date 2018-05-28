#include"CashInATM.h"

CashInATM::CashInATM(int p, int Balance) :RegularATM(p, Balance)
{}

result_en CashInATM::deposit(int amount) {
	if (isLocked) {
		return res_atm_blocked;
	}
	else {
		if (amount > 0) {
			accountBalance += amount;
			isLocked = true;
			return res_ok;
		}
		else {
			isLocked = true;
			return res_error;
		}
	}

	return res_error;
}
void CashInATM::serviceInfo(atmInfo &info, string &address) {
	info.accountBalance = accountBalance;
	info.isLocked = isLocked;
	info.limit = limit;
	address = "Maœlana 134";
}