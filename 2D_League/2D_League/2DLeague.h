#include <iostream>
#include <string>
using namespace std;


// Pre-condition: None
// Post-condition: User selects what they would like to do and the function
//                 returns the user's selection (instructions, start game, exit).
int StartMenu();

// Pre-condition: User has decided to begin the game
// Post-condition: User has selected their role and function returns the role selected (int).
int roleSelection();

// Pre-condition: After role selection begins, user can decide to display each role's stats
// Post-condition: All stats have been printed, user still need to select role
void printStats();

// Pre-condition: User has selected to see how to play 2D League
// Post-condition: Program displays the game's set of instructions
void printInstructions();

// Each function prints the board in its respective position
void printBoardL();
void printBoardM();
void printBoardR();
// printBoard(int) is basically used as a switch statement to decide which board to print
void printBoard(int position);

// Pre-condition: Player has selected to enter the shop and buy one boost
// Post-condition: Player has selected what to buy, stats have been boosted,
//                 cost of item subtracted from player's total gold.
void Shop(Player &player);

void playTurn(Player &playerMoving, Player &playerIdle, Base &movingBase, Base &idleBase, string name, string name2);


// Pre-condition: Each player has been created and owns Turrets, Nexus, Gold, and attributes
// Post-condition: Game has ended, winner (represented by 1 or 2) is returned
int GamePlay(Player &Player1, Player &Player2, Base &p1Base, Base &p2Base);