#pragma once

#include <iostream>
#include "time.h"
#include "stdlib.h"
#include "Random.h"

using namespace std;

class Living {

protected:

	string name;
	string weapon;
	int hp;
	int offensive;

public:

	void setName(string name) {

		this->name = name;
	}
	string getName() {

		return this->name;
	}
	void setWeapon(string weapon) {

		this->weapon = weapon;
	}
	string getWeapon() {

		return this->weapon;
	}
	void setHp(int hp) {

		this->hp = hp;
	}
	int getHp() {

		return this->hp;
	}
	void setOffensive(int offensive) {

		this->offensive = offensive;
	}
	int getOffensive() {

		return this->offensive;
	}
	virtual void attack() {
	}
};
