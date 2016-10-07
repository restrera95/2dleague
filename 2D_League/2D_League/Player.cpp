#include "Player.h"
#include <iostream>
#include <string>

using namespace std;


Player::Player(int selection){
	m_Turrets = 3;
	m_Nexus = true;
	m_Gold = 500;
	m_Status = BASE;
	

	switch (selection) {
	case 0:
		m_Role = MAGE;
		m_PokeDmg = VERY_STRONG;
		m_TurretDmg = WEAK;
		m_PokeResist = AVERAGE;
		m_MaxHP = AVERAGE;
		m_Agility = WEAK;
		break;
	case 1:
		m_Role = MARKSMAN;
		m_PokeDmg = AVERAGE;
		m_TurretDmg = VERY_STRONG;
		m_PokeResist = AVERAGE;
		m_MaxHP = VERY_WEAK;
		m_Agility = STRONG;
		break;
	case 2:
		m_Role = SUPPORT;
		m_PokeDmg = WEAK;
		m_TurretDmg = VERY_WEAK;
		m_PokeResist = STRONG;
		m_MaxHP = VERY_STRONG;
		m_Agility = AVERAGE;
		break;
	case 3:
		m_Role = TANK;
		m_PokeDmg = VERY_WEAK;
		m_TurretDmg = STRONG;
		m_PokeResist = VERY_STRONG;
		m_MaxHP = STRONG;
		m_Agility = VERY_WEAK;
		break;
	case 4:
		m_Role = ASSASSIN;
		m_PokeDmg = STRONG;
		m_TurretDmg = AVERAGE;
		m_PokeResist = VERY_WEAK;
		m_MaxHP = WEAK;
		m_Agility = VERY_STRONG;
		break;
	default:
		m_Role = FIGHTER;
		m_PokeDmg = AVERAGE;
		m_TurretDmg = AVERAGE;
		m_PokeResist = AVERAGE;
		m_MaxHP = AVERAGE;
		m_Agility = AVERAGE;
		break;

	}
	m_CurrHP = 100;
}

int Player::GetRole() {
	return m_Role;
}
int Player::GetStatus() {
	return m_Status;
}
void Player::ChangeStatus(int newStatus) {
	m_Status = newStatus;
}

int Player::GetTurretHP() {
	return m_TurretHP;
}
void Player::TurretHit() {
	m_TurretHP -= 1;
}
int Player::GetTurrets() {
	return m_Turrets;
}
void Player::TurretDestroyed() {
	m_Turrets -= 1;
}


bool Player::HasNexus() {
	return m_Nexus;
}
void Player::NexusDestroyed() {
	m_Nexus = false;
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

void Player::takeDmg(int amount) {
	m_CurrHP -= amount;
	cout << "CURRENT HP: " << m_CurrHP << endl;
}
void Player::PrintCurrHP() {
	cout << m_CurrHP << "/" << m_MaxHP;
}
int Player::GetMaxHP() {
	return m_MaxHP;
}
int Player::GetPokeDmg() {
	return m_PokeDmg;
}
int Player::GetPokeResist() {
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
void Player::IncPokeDmg(int amount) {
	m_PokeDmg += amount;
}
void Player::IncPokeResist(int amount) {
	m_PokeResist += amount;
}
void Player::IncTurretDmg(int amount) {
	m_TurretDmg += amount;
}
void Player::IncAgility(int amount) {
	m_Agility += amount;
}


void Player::Attack(Player &victim, int amount) {
	victim.takeDmg(amount);
}

