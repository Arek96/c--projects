#include "ATM.h"

ATM::ATM(int p, int Balance)
{
	limit = 1000;
	pin = p;
	isLocked = true;
	accountBalance = Balance;
};

	result_en ATM::unlock(int pinCode) {
		if (pinCode == pin) {
			isLocked = false;
			return res_ok;
		}
		else {
			return res_wrong_pin;
		}
	}
	result_en ATM::withdraw(int amount_of_withdrawal) {
		if (isLocked) {
			return res_atm_blocked;
		}
		else {
			if (amount_of_withdrawal < limit) {
				if(amount_of_withdrawal<accountBalance){
					if (amount_of_withdrawal > 0) {
						accountBalance -= amount_of_withdrawal;
						isLocked = true;
						return res_ok;
					}
					else {
						isLocked = true;
						return res_error;
					}
				}
				else {
					isLocked = true;
					return res_no_funds;
				}
				isLocked = true;
				return res_error;
			}
			else {
				isLocked = true;
				return res_withdraw_limit;
			}
		}
	 }
	void ATM::serviceInfo(atmInfo &info, string &address) {
		info.accountBalance = accountBalance;
		info.isLocked = isLocked;
		info.limit = limit;
		address = "Ogórkowa 5";
 }