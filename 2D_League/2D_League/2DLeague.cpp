#include "Player.h"
#include "2DLeague.h"
#include <iostream>
#include <string>

using namespace std;
int boardPosition = 0;

int StartMenu() {
	int selection = -1;
	cout << "~~~~~WELCOME to 2D League!~~~~~~" << endl;
	cout << "1. How to Play" << endl;
	cout << "2. Start game" << endl;
	cout << "3. Exit\n" << endl;
	
	while (selection != 1 && selection != 2 && selection != 3) {
		cout << "What would you like to do?: ";
		cin >> selection;
		if (selection != 1 && selection != 2 && selection != 3)
			cout << "invalid input" << endl;
	}
	return selection;
}
int roleSelection() {
	int roleSelection = 0;
	
	while (roleSelection == 0) {
		cout << "0. View Stats" << endl;
		cout << "1. Mage" << endl;
		cout << "2. Marksman" << endl;
		cout << "3. Support" << endl;
		cout << "4. Tank" << endl;
		cout << "5. Assassin" << endl;
		cout << "6. Fighter" << endl;
		cout << "Choose a role: " << endl;
		cin >> roleSelection; //no validation
		if (roleSelection == 0)
			printStats();
	}
	switch (roleSelection) {
	
	case 1:
		return MAGE;
		break;
	case 2:
		return MARKSMAN;
		break;
	case 3:
		return SUPPORT;
		break;
	case 4:
		return TANK;
		break;
	case 5:
		return ASSASSIN;
		break;
	case 6:
		return FIGHTER;
		break;
	}

}

void printStats() {
	system("CLS");
	cout << "         ----------         " << endl;
	cout << "------------Mage------------" << endl;
	cout << "         ----------         " << endl;
	cout << "Poke Damage      : [][][][][]" << endl;
	cout << "Turret Strength  : [][] " << endl;
	cout << "Poke Resistance  : [][][]" << endl;
	cout << "Health           : [][][]" << endl;
	cout << "Agility          : [][]" << endl << endl;

	cout << "         ----------         " << endl;
	cout << "----------Marksman----------" << endl;
	cout << "         ----------         " << endl;
	cout << "Poke Damage      : [][][]" << endl;
	cout << "Turret Strength  : [][][][][]" << endl;
	cout << "Poke Resistance  : [][]" << endl;
	cout << "Health           : []" << endl;
	cout << "Agility          : [][][][]" << endl << endl;

	cout << "         ---------         " << endl;
	cout << "----------Support----------" << endl;
	cout << "         ---------         " << endl;
	cout << "Poke Damage      : [][]" << endl;
	cout << "Turret Strength  : []" << endl;
	cout << "Poke Resistance  : [][][][]" << endl;
	cout << "Health           : [][][][][]" << endl;
	cout << "Agility          : [][][]" << endl << endl;

	cout << "         ----------         " << endl;
	cout << "------------Tank------------" << endl;
	cout << "         ----------         " << endl;
	cout << "Poke Damage      : []" << endl;
	cout << "Turret Strength  : [][][][]" << endl;
	cout << "Poke Resistance  : [][][][][]" << endl;
	cout << "Health           : [][][][]" << endl;
	cout << "Agility          : []" << endl << endl;


	cout << "         ----------         " << endl;
	cout << "----------Assassin----------" << endl;
	cout << "         ----------         " << endl;
	cout << "Poke Damage      : [][][][]" << endl;
	cout << "Turret Strength  : [][][]" << endl;
	cout << "Poke Resistance  : []" << endl;
	cout << "Health           : [][]" << endl;
	cout << "Agility          : [][][][][]" << endl << endl;

	cout << "         ---------         " << endl;
	cout << "----------Fighter----------" << endl;
	cout << "         ---------         " << endl;
	cout << "Poke Damage      : [][][]" << endl;
	cout << "Turret Strength  : [][][]" << endl;
	cout << "Poke Resistance  : [][][]" << endl;
	cout << "Health           : [][][]" << endl;
	cout << "Agility          : [][][]" << endl << endl;
}
void printInstructions() {
	system("CLS");
	cout << "---------------------------------------" << endl;
	cout << "--------------HOW TO PLAY--------------" << endl;
	cout << "---------------------------------------" << endl << endl;
	cout << "2D league is a two-player turn-based strategy game. Each player\n"
		<< "has three Turrets and one Nexus. Your objective is to destroy\n"
		<< "all of your opponent's Turrets and their Nexus while defending\n"
		<< "your own.\nThere are minion" << endl;
}

void printBoardL() {
	cout <<"0---0                         0---0\n"
		<< "0   0      |                  0   0\n"
		<< "0   0      |                  0   0\n"
		<< "0   0     \\|/                 0   0\n"
		<< "0---0     ___   ___   ___     0---0" << endl;
}
void printBoardM() {
	cout <<"0---0                         0---0\n"
		<< "0   0            |            0   0\n"
		<< "0   0            |            0   0\n"
		<< "0   0           \\|/           0   0\n"
		<< "0---0     ___   ___   ___     0---0" << endl;
}
void printBoardR() {
	cout <<"0---0                         0---0\n"
		<< "0   0                  |      0   0\n"
		<< "0   0                  |     0   0\n"
		<< "0   0                 \\|/     0   0\n"
		<< "0---0     ___   ___   ___     0---0" << endl;
}
void printBoard(int position) {
	if (position == -1)
		printBoardL();
	if (position == 0)
		printBoardM();
	if (position == 1)
		printBoardR();

}


void playTurn(Player &playerMoving, Player &playerIdle, string name, string name2) {
	system("CLS");
	printBoard(boardPosition);

	cout << name << "'s turn starting." << endl;
	int actionSelection;
	//cout << playerMoving.GetStatus();

	switch (playerMoving.GetStatus()) {
	case BASE:
		cout << "Gold Available: " << playerMoving.GetGold() << endl;
		cout << "0. Shop" << endl;
		cout << "1. Walk to lane" << endl;
		cin >> actionSelection;
		switch (actionSelection) {
		case 0:
			break;
		case 1:
			playerMoving.ChangeStatus(LANE);
			cout << name <<" is walking to lane" << endl;
			
			system("PAUSE");
			break;
		}
		break;
	case LANE:
		cout << "0. Poke enemy" << endl;
		cout << "1. Farm minion wave" << endl;
		cout << "2. Hit Turret" << endl;
		cin >> actionSelection;
		switch (actionSelection) {
		case 0:
			playerMoving.Attack(playerIdle, 20);
			cout << name2<<" now has "; 
			playerIdle.PrintCurrHP();
			cout << " health points." << endl;
			system("PAUSE");
			break;
		case 1:
			boardPosition = 1;
			break;
		case 2:

			break;
		}
		break;
	case DEAD:
		break;
	}
	cout << "End of "<< name <<"'s turn." << endl << endl;
}

int GamePlay(Player Player1, Player Player2) {
	
	printBoard(boardPosition);
	int num1 = 0, num2 = 1;
	while (Player1.HasNexus() && Player2.HasNexus()) {
		

		if (num1 == 0 && num2 == 1) {
			playTurn(Player1, Player2, "Player 1", "Player 2");
			num1++;
			num2--;
			cout << "Numbers inverted scenario 1" << endl;
		}
		else {
			playTurn(Player2, Player1, "Player 2", "Player 1");
			num1--;
			num2++;
			cout << "Numbers inverted scenario 2" << endl;
		}

	}

	if (Player1.HasNexus() == 0)
		return 1;
	else if (Player2.HasNexus() == 0)
		return 0;
}


int main() {
	int selection = StartMenu();

	switch (selection) {
	case 1: {
		printInstructions();
		system("PAUSE");
		break;
	}
	case 2: {
		int p1Role, p2Role;

		system("CLS");
		cout << "GAME SETTINGS" << endl << endl;
		cout << "Player 1, select your role." << endl;
		p1Role = roleSelection();
		cout << endl;
		cout << "Player 2, select your role." << endl;
		p2Role = roleSelection();
		cout << endl;

		cout << "Player 1 has selected: " << Roles[p1Role] << endl;
		cout << "Player 2 has selected: " << Roles[p2Role] << endl;
		
		system("PAUSE");
		system("CLS");

		Player Player1(p1Role);
		Player Player2(p2Role);

		int winner;
		winner = GamePlay(Player1, Player2);

		
		system("PAUSE");
		return 0;
		break;
	}
	case 3: {
		return 0;
		break;
	}
	}
	
	
	/*
	//Tests attributes and their accessors/mutators
	
	for (int i = 0; i < 6; i++) {
		cout << "Select a role: ";
		cin >> selection;
		Player player1(selection);
		cout << player1.GetPokeDmg() << endl;
		cout << player1.GetTurretDmg() << endl;
		cout << player1.GetPokeResist() << endl;
		cout << player1.GetMaxHP() << endl;
		cout << player1.GetAgility() << endl;
		cout << endl;
	}
	*/

	/*
	//Tests Gold, Turret, Nexus, accessors and mutators
	
	cout << player1.GetGold() << endl;
	cout << player1.GetTurrets() << endl;
	cout << player1.HasNexus() << endl;
	player1.AddGold(300);
	cout << "Adding 300 gold right this moment." << endl;
	cout << player1.GetGold() << endl;

	player1.TurretDestroyed();
	cout << "Player has lost one turret" << endl;
	cout << player1.GetTurrets() << endl;
	*/

	system("pause");
	return 0;
}