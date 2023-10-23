#include<iostream>//library
using namespace std;

void BattleSystem();
int MonsterGen();
int PlayerHealth = 50; //global variables

int main() { //starting point of program
	int room = 1;
	char input = 'a';
	srand(time(NULL)); //pulling a random seed based off the computer's clock
	while (PlayerHealth >= 0 && input != 'q') { //game loop
		switch (room) {
		case 1:
			cout << "you're in room 1, you can go(s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:

			cout << "you''re in room 2, you can go(n)orth. There's a monster in the corner. (a) to attack!" << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			else if (input == 'a')
				BattleSystem();
			if (PlayerHealth <= 0)
				break;

			break;

		}
	}//end game loop
	if (PlayerHealth <= 0)
		cout << "Game over!" << endl;
}

int MonsterGen() {
	int num = rand() % 100;
	if (num < 50) {
		cout << "a skeleton spawned!" << endl;
		return 1;
	}
	else {
		cout << "a spider appears and attacks!" << endl;
		return 2;
	}
}


void BattleSystem() {
	int MonsterType = MonsterGen();
	int MonsterHealth = 0; //default value, will be rewritten
	int MonsterAtk = 0;
	int PlayerAtk = 0;

	if (MonsterType == 1) // skeleton
		MonsterHealth = 40;
	else if (MonsterType == 2) { //spider
		MonsterHealth = 20;
	}


	while (MonsterHealth > 0 && PlayerHealth > 0) {
		if (MonsterType == 1)
			MonsterAtk = rand() % 25; //can hit from 0-24
		else if (MonsterType == 2)
			MonsterAtk = rand() % 10 + 5; //can hit from 5 to 14
		cout << "The monster attacks you for " << MonsterAtk << " dmg!" << endl;

		PlayerHealth -= MonsterAtk;

		PlayerAtk = rand() % 11 + 20; //player hits for 20-30 dmg
		cout << "the monster attacks you for 10 dmg!" << endl;
		PlayerHealth -= 10;
		cout << "you attack the monster for 10 dmg!" << endl;
		MonsterHealth -= 10;
		system("pause");
		cout << "Your health is now " << PlayerHealth << ", and the monster's health is " << MonsterHealth << endl;


	}
}
