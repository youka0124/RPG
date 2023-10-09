#pragma once

#include "Human.h"
#include "Random.h"

class Brave : public Human {

public:

	Brave(string name, string weapon) {

		this->name = name;
		this->weapon = weapon;

		srand(time(NULL));
		this->hp = Random::getRandom(1, 10);
		this->offensive = Random::getRandom(1, 10);
	}
};
