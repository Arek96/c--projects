#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Klasa zwierz�cia
class CAnimal
{
protected:
	//Lista wyliczeniowa mo�liwych zwierz�t zwierz�t
	enum AnimalType
	{
		Unknown,
		Dog,
		Cat
	} animalType;
	string name;

public:
	CAnimal(const char *name);

	//Wirtualna metoda daj g�os
	virtual void GiveVoice() const;
	//Pobranie nazwy zwierz�ta
	string GetName() const;
	//Pobranie typu zwierz�cia
	string GetType() const;
};

#endif /* ANIMAL_H */