#pragma once

#include "Monster.h"
#include "Random.h"

class Slime : public Monster {

public:

	Slime(string name, string weapon) {

		this->name = name;
		this->weapon = weapon;

		srand(time(NULL));
		this->hp = Random::getRandom(1, 10);
		this->offensive = Random::getRandom(1, 10);
	}
};
