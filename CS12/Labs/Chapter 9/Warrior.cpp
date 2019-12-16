#include "Warrior.h"

Warrior::Warrior(const string& name, double hp, double atk, const string& alliance) : Character(WARRIOR, name, hp, atk) {
	this->alliance = alliance;
}

void Warrior::attack(Character& enemy) {
	if (enemy.getType() == HeroType(WARRIOR)) {
		Warrior& opp = dynamic_cast<Warrior&>(enemy);
		if (alliance == opp.alliance) {
			cout << "Warrior " << name << " does not attack Warrior " << opp.name << "." << endl;
			cout << "They share an allegiance with " << this->alliance << "." << endl;
		}
		else {
			cout << "Warrior " << name << " attacks " << opp.name << " --- SLASH!!" << endl;
			double dmg = (health / MAX_HEALTH) * attackStrength;
			cout << opp.name << " takes " << dmg << " damage." << endl;
			opp.damage(dmg);
		}
	}
	else {
		cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
		double dmg = (health / MAX_HEALTH) * attackStrength;
		cout << enemy.getName() << " takes " << dmg << " damage." << endl;
		enemy.damage(dmg);
	}
}

const string Warrior::getAlliance() const {
	return this->alliance;
}