#include "SuperATM.h"
SuperATM::SuperATM(int p, int Balance) :CashInATM(p,Balance) {

}

result_en SuperATM::rfidWithdraw() {
	if (accountBalance < 50) {
		return res_no_funds;
	}
	else {
		accountBalance -= 50;
		return res_ok;
	}
}
result_en SuperATM::withdraw(int amount) {
	if (amount == 50) return rfidWithdraw();
	else return CashInATM::withdraw(amount);
}

void SuperATM::serviceInfo(atmInfo &info, string &address) {
	info.accountBalance = accountBalance;
	info.isLocked = isLocked;
	info.limit = limit;
	address = "Chmielna 3";
}