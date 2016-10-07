#include <iostream>
#include <string>
using namespace std;

enum roles { MAGE, MARKSMAN, SUPPORT, TANK, ASSASSIN, FIGHTER };
enum strength { ZERO, VERY_WEAK, WEAK, AVERAGE, STRONG, VERY_STRONG };
const string Roles[6] = { "Mage", "Marksman", "Support", "Tank", "Assassin", "Fighter" };
enum location {BASE, LANE, DEAD};

class Player{
public:

	

	Player(int selection);

	int GetRole();
	int GetStatus();
	void ChangeStatus(int newStatus);

	int GetTurretHP();
	void TurretHit();
	int GetTurrets();
	void TurretDestroyed();

	bool HasNexus();
	void NexusDestroyed();

	int GetGold();
	void AddGold(int amount);
	void SpendGold(int itemCost);

	void takeDmg(int amount);
	void PrintCurrHP();
	int GetMaxHP();
	int GetPokeDmg();
	int GetPokeResist();
	int GetTurretDmg();
	int GetAgility();

	//buying boosts
	void IncCurrHP(int amount);
	void IncMaxHP(int amount);
	void IncPokeDmg(int amount);
	void IncPokeResist(int amount);
	void IncTurretDmg(int amount);
	void IncAgility(int amount);

	void Attack(Player &victim, int amount);

private:
	int m_Turrets;
	int m_TurretHP;
	bool m_Nexus;
	int m_Gold;

	int m_CurrHP;
	int m_MaxHP;
	int m_PokeDmg;
	int m_PokeResist;
	int m_TurretDmg;
	int m_Agility;

	int m_Role;
	int m_Status;
};

