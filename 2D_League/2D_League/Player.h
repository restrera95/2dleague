#include <iostream>
using namespace std;

class Player{
public:

	Player(int selection);

	int GetTurrets();
	void TurretDestroyed();

	bool HasNexus();
	void NexusDestroyed();

	int GetGold();
	void AddGold(int amount);
	void SpendGold(int itemCost);

private:
	int m_Turrets;
	bool m_Nexus;
	int m_Gold;
	int m_role;

	int m_CurrHP;
	int m_MaxHp;
	int pokeDmg;
	int DmgResist;
	int tStrength;
	int agility;
};

