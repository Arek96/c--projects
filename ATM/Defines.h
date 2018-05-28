#pragma once
#define USER_NAME    "Imi�"         //Prosz� wpisa� swoje Imi�
#define USER_SURNAME "Nazwisko"     //Prosz� wpisa� swoje Nazwizko
#define USER_GROUP   0 				//Prosz� wpisac numer grupy

struct atmInfo {
	int accountBalance;
	bool isLocked;
	int limit;
};

enum result_en {
    res_ok,          
	res_wrong_pin,				/*!< niepoprawny pin                */
    res_atm_blocked,            /*!< Bankomat jest zablokowany      */
	res_no_funds,				/*!< brak srodk�w na koncie         */
    res_withdraw_limit,         /*!< Przekroczono limit wyp�aty     */
    res_error,                  /*!< Inny b��d                      */
};
