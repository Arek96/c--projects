#include <iostream>
#include "CList.h"
#include "Defines.h"
#include "Tester.h"
CList::CList() {
	first = 0;
	count = 0;
}
CList::~CList() {
	list_el *temp = first;
	list_el *temporary;
	while (temp != 0) {
		temporary = temp->next;
		temp->p.x = 0;
		temp->p.y = 0;
		temp->p.z = 0;
		temp->next = 0;
		delete temp;
		temp = temporary;
	}
	temporary = 0;
	first = 0;
	delete first;
	delete temporary;
	
}
void CList::push_back(const point_t &p) {
		list_el *nowa = new list_el(p);
		if (first == 0) {
			first = nowa;
			count++;
			nowa->next = 0;
	}
		else
		{
			list_el *temp = first;
			while (temp->next) {
				temp = temp->next;
				count++;
				}
			temp->next = nowa;
			nowa->next = 0;
			count++;
		}
}
result_en CList::pop_back() {
	
	if (first == 0)
		return res_error;
	else 
	{
		if (first->next) {
			list_el *temp = first;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			
			delete temp->next;
			temp->next = NULL;
			count--;
			return res_ok;
		}
		else {
			delete first;
			first->next = NULL;
			first->p.x = NULL;
			first->p.y = NULL;
			first->p.z = NULL;
			first = NULL;
			count--;
			return res_ok;
		}
	}
}
result_en CList::insert(size_t kr, const point_t &p) {
	list_el *temp = first;
	
	if (first == 0) {
		push_back(p);
		return res_ok;
		}
	else {
		if (kr == 0) {
			list_el *nowa = new list_el(p);
			first = nowa;
			nowa->next = temp;
			count++;
			return res_ok;
		}
		else {
			if (kr > size()) return res_out_of_range;
			else {
				int i = 0;
				list_el *wskaznik = 0;
				while (i <= kr - 1) {
					wskaznik = temp;
					i++;
					temp = temp->next;

				}

				list_el *nowa = new list_el(p);
				wskaznik->next = nowa;
				nowa->next = temp;
				count++;
				return res_ok;
			}
		}
	}
	
}
result_en CList::find(const point_t &p, size_t &kr) const 
{
	list_el *temp = first;
	
	size_t i = 0;
	if (first == 0) {
		return res_error;
	}
	else {
		while (temp) {
			
			if (p.x == temp->p.x && p.y == temp->p.y && p.y == temp->p.y) {
				kr = i;	
				count = i + 1;
				return res_ok;
			}
			temp = temp->next;
			i++;
		}
		return res_out_of_range;
	}
}
result_en CList::get(size_t kr, point_t &p) const {
	list_el *temp = first;
	
	size_t i = 0;
	if (first == 0) {
		return res_error;
	}
	else {
		while (temp ) {
			if (i == kr) {
				p = temp->p;
			
				count = i+1;
				return res_ok;
			}
			
			temp = temp->next;
			i++;
		}
		return res_out_of_range;
	}
}
size_t CList::size() const 
{
	
	if (first == 0)
		return 0;
	else {
		list_el *temp = first;
		
		size_t wynik = 0;
		size_t cout = wynik;
		while (temp )
		{
			temp = temp->next;
			wynik++;
		}
		return count;
	}

	}
