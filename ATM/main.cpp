#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <vector>

int main()
{
	CAnimal animal("Wielka stopa");
	CCat cat("Puszek");
	CDog dog("Azor");

	vector<CAnimal *> zoo;
	zoo.push_back(&animal);
	zoo.push_back(&cat);
	zoo.push_back(&dog);

	for(vector<CAnimal *>::iterator it = zoo.begin(); it != zoo.end(); it++)
	{
		CAnimal &animal = **it;
		cout << "Zwierze typu \'" << animal.GetType() << "\' o imieniu \'" << animal.GetName() << "\' wydaje glos: ";
		animal.GiveVoice();
	}

	system("pause");
}