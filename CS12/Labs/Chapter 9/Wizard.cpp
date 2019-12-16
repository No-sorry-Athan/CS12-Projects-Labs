#include "Wizard.h"

Wizard::Wizard(const string& name, double hp, double atk, int rank) :Character(WIZARD, name, hp, atk){
	this->rank = rank;
}

const int Wizard::getRank() const {
	return this->rank;
}

void Wizard::attack(Character& enemy) {
	if (enemy.getType() == HeroType(WIZARD)) {
		Wizard& opp = dynamic_cast<Wizard&>(enemy);
		cout << "Wizard " << name << " attacks " << opp.name << " --- POOF!!" << endl;
		double dmg = ((double)rank/opp.rank) * attackStrength;
		cout << opp.name << " takes " << dmg << " damage." << endl;
		opp.damage(dmg);
	}
	else {
		cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
		double dmg = attackStrength;
		cout << enemy.getName() << " takes " << dmg << " damage." << endl;
		enemy.damage(dmg);
	}
}