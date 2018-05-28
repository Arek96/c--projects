#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Klasa zwierzêcia
class CAnimal
{
protected:
	//Lista wyliczeniowa mo¿liwych zwierz¹t zwierz¹t
	enum AnimalType
	{
		Unknown,
		Dog,
		Cat
	} animalType;
	string name;

public:
	CAnimal(const char *name);

	//Wirtualna metoda daj g³os
	virtual void GiveVoice() const;
	//Pobranie nazwy zwierzêta
	string GetName() const;
	//Pobranie typu zwierzêcia
	string GetType() const;
};

#endif /* ANIMAL_H */