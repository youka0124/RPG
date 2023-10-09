#pragma once

#include "Human.h"
#include "Random.h"

class Fighter : public Human {

public:

	Fighter(string name, string weapon) {

		this->name = name;
		this->weapon = weapon;

		srand(time(NULL));
		this->hp = Random::getRandom(1, 10);
		this->offensive = Random::getRandom(1, 10);
	}
};
