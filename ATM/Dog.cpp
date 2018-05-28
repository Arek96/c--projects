#include "Dog.h"

CDog::CDog(const char *name) : CAnimal(name)
{
	animalType = Dog;
}

void CDog::GiveVoice() const
{
	cout << "Hal! Hal!" << endl;
	Beep(500, 500);
	Beep(500, 500);
}