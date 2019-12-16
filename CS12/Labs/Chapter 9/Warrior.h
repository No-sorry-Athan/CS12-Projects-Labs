#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
#include <iostream>
class Warrior: public Character {
private:
	string alliance;
public:
	Warrior(const string&, double, double, const string&);
	const string getAlliance() const;
	void attack(Character&) override;
};

#endif
