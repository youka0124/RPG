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

		cout << "�u" << this->getName() << "�v��" << "�u" << this->getWeapon() << "�v�ōU���I" << "�u" << living->getName() << "�v" << "�� " << damege << " �̃_���[�W��^�����B" << endl;
	}
};
