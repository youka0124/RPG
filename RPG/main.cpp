#include <vector>
#include "Brave.h"
#include "Fighter.h"
#include "Wizard.h"
#include "Slime.h"
#include "Oak.h"
#include "Dragon.h"
#include "Random.h"

Human* choiceHuman(vector<Human*>* humans) {

	srand(time(NULL));
	return humans->at(Random::getRandom(0, humans->size() - 1));
}

Monster* choiceMonster(vector<Monster*>* monsters) {

	srand(time(NULL));
	return monsters->at(Random::getRandom(0, monsters->size() - 1));
}

void showGroupInfos(vector<Human*>* humans, vector<Monster*>* monsters) {

	cout << "[�l�ԃO���[�v]:" << humans->size() << "�l" << endl;
	cout << "[�����X�^�[�O���[�v]:" << monsters->size() << "�l" << endl;
}

int main() {

	cout << "���� ==== �킢�̊J�n���I�I ==== ����" << endl;

	Human* brave = new Brave("brave", "soword");
	Human* fighter = new Fighter("fighter", "gun");
	Human* wizard = new Wizard("wizard", "cane");

	vector<Human*> humans;
	humans.push_back(brave);
	humans.push_back(fighter);
	humans.push_back(wizard);

	Monster* slime = new Slime("slime", "axe");
	Monster* oak = new Oak("oak", "spear");
	Monster* dragon = new Dragon("dragon", "bow");

	vector<Monster*> monsters;
	monsters.push_back(slime);
	monsters.push_back(oak);
	monsters.push_back(dragon);

	showGroupInfos(&humans, &monsters);

	int count = 1;

	while (true) {

		cout << "���@��" << count << "���" << endl;

		cout << "[�l�Ԃ̃^�[���I]" << endl;

		Human* human = choiceHuman(&humans);
		Monster* monster = choiceMonster(&monsters);

		cout << "�l�ԃO���[�v����" << "�u" << human->getName() << "�v�̂��o�܂����I" << endl;

		cout << "�����X�^�[�O���[�v����" << "�u" << monster->getName() << "�v�̂��o�܂����I" << endl;

		human->attack(monster);

		if (monster->getHp() <= 0) {
			for (vector<Monster*>::iterator it = monsters.begin(); it != monsters.end();) {
				if ((*it) == monster) {

					it = monsters.erase(it);
				}
				else {

					++it;
				}
			}
		}

		if (monsters.size() == 0) {

			cout << "�l�ԃO���[�v�̏���" << endl;
			break;
		}

		cout << "[�����X�^�[�̃^�[��!]" << endl;

		human = choiceHuman(&humans);
		monster = choiceMonster(&monsters);

		cout << "�l�ԃO���[�v����" << "�u" << human->getName() << "�v�̂��o�܂����I" << endl;
		;
		cout << "�����X�^�[�O���[�v����" << "�u" << monster->getName() << "�v�̂��o�܂����I" << endl;

		monster->attack(human);

		if (human->getHp() <= 0) {

			for (vector<Human*>::iterator it = humans.begin(); it != humans.end();) {

				if ((*it) == human) {

					it = humans.erase(it);
				}
				else {

					++it;
				}
			}
		}

		if (humans.size() == 0) {

			cout << "�����X�^�[�O���[�v�̏���" << endl;
			break;
		}

		showGroupInfos(&humans, &monsters);

		count++;
	}

	showGroupInfos(&humans, &monsters);

	return 0;
}