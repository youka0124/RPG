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

		cout << "�u" << this->getName() << "�v��" << "�u" << this->getWeapon() << "�v�ōU���I�u" << monster->getName() << "�v�� " << damege << " �̃_���[�W��^�����B" << endl;
		cout << "�����������̍U���͂��P���������B" << endl;
	}
};
