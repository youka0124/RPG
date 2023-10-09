#pragma once

#include "time.h"
#include "stdlib.h"
#include "Living.h"
#include "Human.h"

class Monster : public Living {

public:

	void attack(Living* living) {

		int damege = this->offensive;

		int humanHp = living->getHp();
		humanHp -= damege;
		living->setHp(humanHp);

		cout << "「" << this->getName() << "」が" << "「" << this->getWeapon() << "」で攻撃！" << "「" << living->getName() << "」" << "に " << damege << " のダメージを与えた。" << endl;
	}
};
