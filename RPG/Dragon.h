#pragma once

#include "Monster.h"
#include "Random.h"

class Dragon : public Monster {

public:

	Dragon(string name, string weapon) {

		this->name = name;
		this->weapon = weapon;

		srand(time(NULL));
		this->hp = Random::getRandom(1, 10);
		this->offensive = Random::getRandom(1, 10);
	}
};
