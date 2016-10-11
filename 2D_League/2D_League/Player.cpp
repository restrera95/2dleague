#include "Player.h"
#include <iostream>
#include <string>

using namespace std;


Player::Player(int selection){

	m_Gold = 500;
	m_Status = BASE;
	

	switch (selection) {
	case 0:
		m_Role = MAGE;
		m_PokeDmg = (VERY_STRONG * 4) + 20;
		m_TurretDmg = WEAK;
		m_PokeResist = AVERAGE * 0.05;
		m_MaxHP = AVERAGE * 20 + 100;
		m_Agility = WEAK;
		break;
	case 1:
		m_Role = MARKSMAN;
		m_PokeDmg = AVERAGE * 4 + 20;
		m_TurretDmg = VERY_STRONG;
		m_PokeResist = AVERAGE * 0.05;
		m_MaxHP = VERY_WEAK * 20 + 100;
		m_Agility = STRONG;
		break;
	case 2:
		m_Role = SUPPORT;
		m_PokeDmg = WEAK * 4 + 20;
		m_TurretDmg = VERY_WEAK;
		m_PokeResist = STRONG * 0.05;
		m_MaxHP = VERY_STRONG * 20 + 100;
		m_Agility = AVERAGE;
		break;
	case 3:
		m_Role = TANK;
		m_PokeDmg = VERY_WEAK * 4 + 20;
		m_TurretDmg = STRONG;
		m_PokeResist = VERY_STRONG * 0.05;
		m_MaxHP = STRONG * 20 + 100;
		m_Agility = VERY_WEAK;
		break;
	case 4:
		m_Role = ASSASSIN;
		m_PokeDmg = STRONG * 4 + 20;
		m_TurretDmg = AVERAGE;
		m_PokeResist = VERY_WEAK * 0.05;
		m_MaxHP = WEAK * 20 + 100;
		m_Agility = VERY_STRONG;
		break;
	case 5:
		m_Role = FIGHTER;
		m_PokeDmg = AVERAGE * 4 + 20;
		m_TurretDmg = AVERAGE;
		m_PokeResist = AVERAGE * 0.05;
		m_MaxHP = AVERAGE * 20 + 100;
		m_Agility = AVERAGE;
		break;

	}
	m_CurrHP = m_MaxHP;
}

int Player::GetRole() {
	return m_Role;
}
int Player::GetStatus() {
	return m_Status;
}
void Player::ChangeStatus(int newStatus) {
	m_Status = newStatus;
	if (m_Status == BASE)
		m_CurrHP = m_MaxHP;
}


int Player::GetGold() {
	return m_Gold;
}
void Player::AddGold(int amount) {
	m_Gold += amount;
}
void Player::SpendGold(int itemCost) {
	m_Gold -= itemCost;
}

void Player::takeDmg(double amount) {
	m_CurrHP -= amount - amount * m_PokeResist;
	cout << "Damage dealt: " << amount << endl;
	cout << "poke resist: " << m_PokeResist << endl;
	cout << "CURRENT HP: " << m_CurrHP << endl;
}
void Player::PrintCurrHP() {
	cout << m_CurrHP << "/" << m_MaxHP;
}
int Player::GetCurrHP() {
	return m_CurrHP;
}
int Player::GetMaxHP() {
	return m_MaxHP;
}
double Player::GetPokeDmg() {
	return m_PokeDmg;
}
double Player::GetPokeResist() {
	return m_PokeResist;
}
int Player::GetTurretDmg() {
	return m_TurretDmg;
}
int Player::GetAgility(){
	return m_Agility;
}

void Player::IncCurrHP(int amount) {
	m_CurrHP += amount;
}
void Player::IncMaxHP(int amount) {
	m_MaxHP += amount;
}
void Player::IncPokeDmg(double amount) {
	m_PokeDmg += amount;
}
void Player::IncPokeResist(double amount) {
	m_PokeResist += amount;
}
void Player::IncTurretDmg(int amount) {
	m_TurretDmg += amount;
}
void Player::IncAgility(int amount) {
	m_Agility += amount;
}


void Player::Attack(Player &victim, double amount) {
	victim.takeDmg(amount);
}

