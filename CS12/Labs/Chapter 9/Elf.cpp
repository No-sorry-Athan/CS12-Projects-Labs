#include "Elf.h"

Elf::Elf(const string& name, double hp, double atk, const string& familyName) : Character(ELF, name, hp, atk) {
	this->familyName = familyName;
}

void Elf::attack(Character& enemy) {
	if (enemy.getType() == HeroType(ELF)) {
		Elf& opp = dynamic_cast<Elf&>(enemy);
		if (familyName == opp.familyName) {
			cout << "Elf " << name << " does not attack Elf " << opp.name << "." << endl;
			cout << "They are both members of the " << this->familyName << " family." <<endl;
		}
		else {
			cout << "Elf " << name << " shoots an arrow at " << opp.name << " --- TWANG!!" << endl;
			double dmg = (health / MAX_HEALTH) * attackStrength;
			cout << opp.name << " takes " << dmg << " damage." << endl;
			opp.damage(dmg);
		}
	}
	else {
		cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
		double dmg = (health / MAX_HEALTH) * attackStrength;
		cout << enemy.getName() << " takes " << dmg << " damage." << endl;
		enemy.damage(dmg);
	}
}

const string Elf::getFamily() const {
	return this->familyName;
}