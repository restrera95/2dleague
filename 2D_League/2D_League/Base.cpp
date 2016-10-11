#include "Base.h"



Base::Base(){
	m_turretOneHP = 3;	
	m_turretTwoHP =	5;
	m_turretThreeHP = 7;
	m_NexusHP = 10;

	currStruct = &m_turretOneHP;
}

void Base::Hit() {
	*currStruct -= 1;
	cout << "Structure HP remaining: " << *currStruct << endl;
	if (*currStruct == 0) {
		cout << "Structure destroyed!" << endl;
		movePTR();
	}
}

void Base::movePTR() {
	cout << "INSIDE movePTR" << endl;
	if (m_turretOneHP == 0) {
		cout << "MOVE MOVE MOVE" << endl;
		currStruct = &m_turretTwoHP;
		if (m_turretTwoHP == 0) {
			currStruct = &m_turretThreeHP;
			if (m_turretThreeHP == 0) {
				currStruct = &m_NexusHP;
			}
		}
	} 
}

bool Base::hasNexus() {
	if (m_NexusHP == 0)
		return false;
	else
		return true;
}

void Base::test() {
	cout << &m_turretOneHP << endl;
	cout << currStruct << endl;
}