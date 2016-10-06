#include "Player.h"
#include <iostream>

using namespace std;


Player::Player(int selection){
	m_Turrets = 3;
	m_Nexus = true;
	m_Gold = 100;
	m_role = selection;
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