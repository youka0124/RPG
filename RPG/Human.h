#pragma once

#include "time.h"
#include "stdlib.h"
#include "Living.h"
#include "Monster.h"

class Human : public Living {

public:

	void attack(Monster* monster) {

		int	damege = this->offensive;

		int monsterHp = monster->getHp();
		monsterHp -= damege;
		monster->setHp(monsterHp);

		this->offensive -= 1;

		cout << "「" << this->getName() << "」が" << "「" << this->getWeapon() << "」で攻撃！「" << monster->getName() << "」に " << damege << " のダメージを与えた。" << endl;
		cout << "しかし自分の攻撃力も１減少した。" << endl;
	}
};
