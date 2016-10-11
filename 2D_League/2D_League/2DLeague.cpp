#include "Base.h"
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
		<< "0   0                  |      0   0\n"
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

void Shop(Player &player) {
	cout << "Gold Available: " << player.GetGold() << endl << endl;
	cout << "Welcome to the shop, what would you like to buy?" << endl << endl;
	cout << "0. Poke damage boost" << endl;
	cout << "1. Poke resistance boost" << endl;
	cout << "2. Maximum health" << endl;
	cout << "3. Movement speed" << endl;

	int selection;
	cin >> selection;

	switch (selection){

	case 0:
		player.IncPokeDmg(4);
		cout << "Increasing poke damage...\nPlayer poke damage increased by 4 !" << endl;
		break;
	case 1:
		player.IncPokeResist(0.05);
		cout << "Increasing poke resist...\nPlayer poke resistance increased by 5% !" << endl;
		break;
	case 2:
		player.IncMaxHP(20);
		cout << "Increasing max HP...\nPlayer max HP increased by 20 !" << endl;
		break;
	case 3:
		player.IncAgility(0);
		break;
	}
	player.SpendGold(500);
}

void playTurn(Player &playerMoving, Player &playerIdle, Base &movingBase, Base &idleBase, string name, string name2) {
	system("CLS");
	cout << name << "'s turn starting." << endl << endl;
	printBoard(boardPosition);

	int actionSelection;

	//Displays actions depending on where Player is located
	switch (playerMoving.GetStatus()) {
	case BASE:
		cout << "Gold Available: " << playerMoving.GetGold() << endl;
		cout << "0. Shop" << endl;
		cout << "1. Walk to lane" << endl;
		cin >> actionSelection;
		//OPTIONS AT BASE
		switch (actionSelection) {
		case 0:
			Shop(playerMoving);
			break;
		case 1:
			playerMoving.ChangeStatus(LANE);
			cout << name <<" is walking to lane" << endl;
			break;
		}
		break;

	case LANE:
		cout << "0. Poke enemy" << endl;
		cout << "1. Farm minion wave" << endl;
		cout << "2. Hit Turret" << endl;
		cout << "3. Recall back to base" << endl;
		cin >> actionSelection;
		//OPTIONS IN LANE
		switch (actionSelection) {
		case 0:
			playerMoving.Attack(playerIdle, playerMoving.GetPokeDmg());
			cout << name2 << " now has "; 
			playerIdle.PrintCurrHP();
			cout << " health points." << endl;
			if (playerIdle.GetCurrHP() <= 0)
				playerIdle.ChangeStatus(DEAD);
			break;
		case 1:
			if (name == "Player 1") {
				boardPosition++;
			}
			else if (name == "Player 2")
				boardPosition--;
			playerMoving.AddGold(100);
			cout << "+100 Gold" << endl;
			break;
		case 2:
			idleBase.Hit();
			if (idleBase.hasNexus() == false)
				cout << "Game over baby" << endl;
			break;
		case 3:
			playerMoving.ChangeStatus(BASE);
			cout << "Recalling to base..." << endl;
			break;
		}
		break;
	case DEAD:
		cout << "You've been killed, your turn is skipped." << endl;
		playerMoving.ChangeStatus(BASE);
		break;
	}

	cout << "End of "<< name <<"'s turn." << endl << endl;
	system("PAUSE");
}

int GamePlay(Player &Player1, Player &Player2, Base &p1Base, Base &p2Base) {
	printBoard(boardPosition);
	int num1 = 0, num2 = 1;
	while (p1Base.hasNexus() == true && p2Base.hasNexus() == true) {
		
		//Turns alternate as num1 and num2 alternate values
		if (num1 == 0 && num2 == 1) {
			playTurn(Player1, Player2, p1Base, p2Base, "Player 1", "Player 2");
			num1++;
			num2--;
		}
		else {
			playTurn(Player2, Player1, p2Base, p1Base, "Player 2", "Player 1");
			num1--;
			num2++;
		}

	}

	if (p1Base.hasNexus() == 0)
		return 1;
	else if (p2Base.hasNexus() == 0)
		return 0;
}


int main() {
	int selection = StartMenu();

	//Switch statements 
	switch (selection) {
	case 1: {
		printInstructions();
		system("PAUSE");
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

		Base p1Base;
		Base p2Base;
		Player Player1(p1Role);
		Player Player2(p2Role);
		int winner;
		winner = GamePlay(Player1, Player2, p1Base, p2Base);

		system("CLS");
		if (winner == 0)
			cout << "Player 1 wins!" << endl;
		else if (winner == 1)
			cout << "Player 2 wins!" << endl;

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