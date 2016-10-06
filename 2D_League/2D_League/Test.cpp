#include "Player.h"
#include <iostream>

using namespace std;

int main() {
	Player player1(5);
	cout << player1.GetGold() << endl;
	cout << player1.GetTurrets() << endl;
	cout << player1.HasNexus() << endl;
	player1.AddGold(300);
	cout << "Adding 300 gold right this moment." << endl;
	cout << player1.GetGold() << endl;

	player1.TurretDestroyed();
	cout << "Player has lost one turret" << endl;
	cout << player1.GetTurrets() << endl;

	cin.get();
	return 0;
}