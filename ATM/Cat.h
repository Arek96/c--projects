#ifndef CAT_H
#define CAT_H
#include "Animal.h"

//Klasa kota
class CCat : public CAnimal
{
public:
	CCat(const char *name);
	void GiveVoice() const;
};

#endif /* CAT_H */