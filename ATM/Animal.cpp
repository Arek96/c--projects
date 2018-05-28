#include "Animal.h"

CAnimal::CAnimal(const char *name) :
	animalType(Unknown),
	name(name)
{
}
void CAnimal::GiveVoice() const
{
	cout << "Cisza..." << endl;
	Beep(10000, 1000);
}
string CAnimal::GetName() const
{
	return this->name;
}
string CAnimal::GetType() const
{
	string type;
	switch (this->animalType)
	{
	case Unknown:
		type = "Nieznane";
		break;
	case Dog:
		type = "Pies";
		break;
	case Cat:
		type = "Kot";
		break;
	default:
		break;
	}
	return type;
}