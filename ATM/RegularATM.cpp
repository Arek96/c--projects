#include "RegularATM.h"
RegularATM::RegularATM(int p, int Balance) 
	:
		ATM(p,Balance)
	{
	limit = 10000;
}

result_en RegularATM::checkBalance(int& balance) {
	
	if (isLocked) {
		return res_atm_blocked;
	}
	else {
		balance = accountBalance;
			isLocked = true;
		return res_ok;
	}
	return res_error;
}
void RegularATM::serviceInfo(atmInfo &info, string &address) {
	info.accountBalance = accountBalance;
	info.isLocked = isLocked;
	info.limit = limit;
	address = "Grzybowa 12";
}