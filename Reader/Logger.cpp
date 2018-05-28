#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Defines.h"
#include "Tester.h"
using namespace std;

CLogger::CLogger(string filePath, bool bin ) {

	
	if (bin==true) {
		binary = true;
		file.open(filePath, ios::binary| ios::app );	
	}
	else { 
		file.open(filePath, ios::app);
	}
	
}
CLogger::~CLogger() {
	file.close();
}
result_en CLogger::Log(const point_t &p) {
	
	
	if (file.is_open() == false) {
		return res_file_not_open;
	}
	else {
	
		if (binary == false) {

			file << p.x <<";"<<p.y <<";"<< p.z << "\n";
			
			return res_ok;
		}
		else {
			
			file.write((char *)&p, sizeof(point_t));
			return res_ok;
		}
		}
}
result_en CLogger::Log(const vector<point_t> &m) {
	if (file.is_open()) {
		if (binary == false) {
			int v_size = m.size();
		
			for (int i = 0; i <= v_size -1; i++) {
				point_t point_ = m.at(i);
				
				file << point_.x << ";" << point_.y << ";" << point_.z << endl;
				
			}
			return res_ok;
		}
		else {
			
			int v_size = m.size();
			for (int i = 0; i <= v_size -1 ; i++) {
				point_t point_ = m.at(i);
				file.write((char *)&point_, sizeof(point_t));
				
			}
			return res_ok;
		}
		return res_error;
	}
	else {
		return res_file_not_open;
	}
	}
