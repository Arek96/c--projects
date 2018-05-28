#include "Cat.h"

CCat::CCat(const char *name) : CAnimal(name)
{
	animalType = Cat;
}

void CCat::GiveVoice() const
{
	cout << "Miaaaal!" << endl;
	Beep(1000, 1000);
}