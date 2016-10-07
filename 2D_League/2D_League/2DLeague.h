#include <iostream>
#include <string>
using namespace std;


// Pre-condition: None
// Post-condition: User selects what they would like to and the function
//                 returns the user's selection
int StartMenu();

// Pre-condition: User has decided to begin the game
// Post-condition: User has selected their role
int roleSelection();

// Pre-condition: After role selection begins, user can decide to display each role's stats
// Post-condition: All stats have been printed, user still need to select role
void printStats();

// Pre-condition: User has selected to see how to play 2D League
// Post-condition: Program displays the game's set of instructions
void printInstructions();

void printBoardL();
void printBoardM();
void printBoardR();
void printBoard(int position);

void playTurn(Player &playerMoving, Player &playerIdle, string name, string name2);
// Pre-condition: Each player has been created filled with Turrets, 
//                Nexus, Gold, and attributes
// Post-condition: Game has ended, winner (represented by 1 or 2) is returned
int GamePlay(Player Player1, Player Player2);