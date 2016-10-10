//#include "Base.h"
#include <iostream>
#include <string>
using namespace std;

enum roles { MAGE, MARKSMAN, SUPPORT, TANK, ASSASSIN, FIGHTER };
enum strength { FILL, ZERO, VERY_WEAK, WEAK, AVERAGE, STRONG, VERY_STRONG };
const string Roles[6] = { "Mage", "Marksman", "Support", "Tank", "Assassin", "Fighter" };
enum location {BASE, LANE, DEAD};

class Player{
public:

	Player(int selection);

	//Accessors for Role and Status
	int GetRole();
	int GetStatus();
	//Changes player's location in-game (Base, Lane, Dead)
	void ChangeStatus(int newStatus);


	//All functions related to player's Gold
	int GetGold();
	void AddGold(int amount);
	void SpendGold(int itemCost);

	//Functions used for Attack()
	void takeDmg(double amount);
	void PrintCurrHP();

	//Accessors for player's stats
	int GetMaxHP();
	double GetPokeDmg();
	double GetPokeResist();
	int GetTurretDmg();
	int GetAgility();

	//Mutators used when buying boosts from the shop
	void IncCurrHP(int amount);
	void IncMaxHP(int amount);
	void IncPokeDmg(double amount);
	void IncPokeResist(double amount);
	void IncTurretDmg(int amount);
	void IncAgility(int amount);

	//Mutator used for when a player decides to poke
	void Attack(Player &victim, double amount);

private:

	int m_Gold;

	int m_CurrHP;
	int m_MaxHP;
	double m_PokeDmg;
	double m_PokeResist;
	int m_TurretDmg;
	int m_Agility;

	int m_Role;
	int m_Status;

	
};

