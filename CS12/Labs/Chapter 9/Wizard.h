#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
#include <iostream>
class Wizard: public Character {
private:
	int rank;
public:
	Wizard(const string&, double, double, int);
	const int getRank() const;
	void attack(Character&) override;
};

#endif 
