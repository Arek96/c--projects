#include "BinaryReader.h"
#include <fstream>
#include<iostream>
using namespace std;
CBinaryReader::CBinaryReader(string filePath) {
	file.open(filePath,  ios::in);
}
CBinaryReader::~CBinaryReader() {
	file.close();
}
result_en CBinaryReader::ReadFile(vector<point_t> &pointsVector) {
	if (file.is_open()) {
		file.seekg(0, ios::end);		
		int bytes = file.tellg();
		double pointsCount = bytes / sizeof(point_t);
		
		file.seekg(0, ios::beg);	
		char *buff = new char [sizeof(point_t)];    		
		pointsVector.clear();
		for (int i = 0; i <= pointsCount - 1;i++ ) {
			file.read((char *)buff, sizeof(point_t));
			point_t* punkt = (point_t*)buff;
			
			pointsVector.push_back(*punkt);
			
			
		}
	
		delete buff;
		return res_ok;
	}
	else {
		return res_file_not_open;
	}
}
result_en CBinaryReader::ReadIndex(size_t index, point_t &p) {
	if (file.is_open()) {
		file.seekg(0, ios::end);
		int file_size = file.tellg();
		file.seekg(0, ios::beg);
	
		if (index > file_size/sizeof(point_t)-1) {
			return res_out_of_range;
		}
		else {
			file.seekg(index * sizeof(point_t));
			char *buff = new char[sizeof(point_t)];
			file.read((char*)buff, sizeof(point_t));
			
			if (file.fail()) { 
				delete buff;
				buff = NULL;
				return res_error; 
			}
			else {
				point_t* point = (point_t *)buff;
				p = *point;
				delete buff;
				buff = NULL;
				return res_ok;
			}
		}
	}
	else {
		return res_file_not_open;
	}
	return res_error;
}