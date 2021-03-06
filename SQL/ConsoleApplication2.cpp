#include "stdafx.h" 
#include <iostream>
#include <my_global.h>
#include <mysql.h> 

void finish_with_error(MYSQL *con) {
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(int argc, char **argv) {
	MYSQL *con = mysql_init(NULL);
	if (con == NULL) {
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "aX#>:&^443@dR", "po_db", 0, NULL, 0) == NULL) {
		finish_with_error(con);
	}  
	std::string haslo;
	std::cout << "Podaj hasło: \n";
	std::cin >> haslo;
	std::string query = "SELECT* FROM student WHERE nazwisko='" + haslo + "'";
	if (mysql_query(con, query.c_str())) {
		finish_with_error(con);
	}
	MYSQL_RES *result = mysql_store_result(con);
	if (result == NULL) {

		finish_with_error(con);
	}

	mysql_free_result(result);
	if (mysql_query(con, "SELECT imie FROM student")) {
		finish_with_error(con);
	}
	result = mysql_store_result(con);
	if (result == NULL) {
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
		for (int i = 0; i < num_fields; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}            printf("\n");
	}
	mysql_free_result(result);

	if (mysql_query(con, "SELECT student.imie, student.nazwisko, przedmioty.nazwa_przedmiotu, student_przedmioty.ocena_z_przedmiotu FROM student, przedmioty, student_przedmioty WHERE student.id=student_przedmioty.id_student AND student_przedmioty.id_przedmioty=przedmioty.id AND przedmioty.id = 1")) {
		finish_with_error(con);
	}
	MYSQL_RES *result2 = mysql_store_result(con);
	if (result == NULL) {
		finish_with_error(con);
	}

	int num_fields2 = mysql_num_fields(result2);

	MYSQL_ROW row2;
	while ((row2 = mysql_fetch_row(result2))) {
		for (int i = 0; i < num_fields2; i++) {
			printf("%s ", row2[i] ? row2[i] : "NULL");
		}            printf("\n");
	}
	mysql_free_result(result2);
	mysql_close(con);
	system("pause");
	exit(0);
}