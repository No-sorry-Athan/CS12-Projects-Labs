#include "Character.h"

Character::Character(HeroType type, const string& name, double health, double atk) {
	this->type = type;
	this->name = name;
	this->health = health;
	this->attackStrength = atk;
}

HeroType Character::getType() const {
	return type;
}

const string& Character::getName() const {
	return name;
}

int Character::getHealth() const {
	return static_cast<int>(health);
}

void Character::setHealth(double h) {
	health = h;
}

void Character::damage(double d) {
	setHealth(health - d);
}

bool Character::isAlive() const {
	return health > 0;
}

