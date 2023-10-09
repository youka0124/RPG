#pragma once

#include "Human.h"
#include "Random.h"

class Wizard : public Human {

public:

	Wizard(string name, string weapon) {

		this->name = name;
		this->weapon = weapon;

		srand(time(NULL));
		this->hp = Random::getRandom(1, 10);
		this->offensive = Random::getRandom(1, 10);
	}
};
