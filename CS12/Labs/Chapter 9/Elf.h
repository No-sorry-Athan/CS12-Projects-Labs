#ifndef ELF_H
#define ELF_H
#include "Character.h"
#include <iostream>
class Elf: public Character {
private:
	string familyName;
public:
	Elf(const string&, double, double, const string&);
	const string getFamily() const;
	void attack(Character&) override;
};

#endif
