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

	cout << "[人間グループ]:" << humans->size() << "人" << endl;
	cout << "[モンスターグループ]:" << monsters->size() << "人" << endl;
}

int main() {

	cout << "★★ ==== 戦いの開始だ！！ ==== ★★" << endl;

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

		cout << "★　第" << count << "回戦" << endl;

		cout << "[人間のターン！]" << endl;

		Human* human = choiceHuman(&humans);
		Monster* monster = choiceMonster(&monsters);

		cout << "人間グループから" << "「" << human->getName() << "」のお出ましだ！" << endl;

		cout << "モンスターグループから" << "「" << monster->getName() << "」のお出ましだ！" << endl;

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

			cout << "人間グループの勝利" << endl;
			break;
		}

		cout << "[モンスターのターン!]" << endl;

		human = choiceHuman(&humans);
		monster = choiceMonster(&monsters);

		cout << "人間グループから" << "「" << human->getName() << "」のお出ましだ！" << endl;
		;
		cout << "モンスターグループから" << "「" << monster->getName() << "」のお出ましだ！" << endl;

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

			cout << "モンスターグループの勝利" << endl;
			break;
		}

		showGroupInfos(&humans, &monsters);

		count++;
	}

	showGroupInfos(&humans, &monsters);

	return 0;
}