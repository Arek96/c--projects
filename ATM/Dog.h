#ifndef DOG_H
#define DOG_H
#include "Animal.h"

//Klasa psa
class CDog : public CAnimal
{
public:
	CDog(const char *name);
	void GiveVoice() const;
};

#endif /* DOG_H */