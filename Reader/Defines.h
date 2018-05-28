#pragma once
#define USER_NAME    "Imi�"         //Prosz� wpisa� swoje Imi�
#define USER_SURNAME "Nazwisko"     //Prosz� wpisa� swoje Nazwizko
#define USER_GROUP   0 				//Prosz� wpisac numer grupy

struct point_t
{
    double x, y, z;
};

enum result_en {
    res_ok,             
    res_file_not_open,          /*!< Plik nie zosta� poprawnie otwarty      */
    res_out_of_range,           /*!< Podany indeks przekracza rozmiar pliku */
    res_error,                  /*!< Inny b��d                              */
};
