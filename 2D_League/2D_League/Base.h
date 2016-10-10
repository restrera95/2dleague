#include <iostream>
#include <string>
using namespace std;


class Base{

public:
	Base();
	void Hit();
	void movePTR();

	bool hasNexus();

	void test();

private:

	int m_turretOneHP;
	int m_turretThreeHP;
	int m_turretTwoHP;
	int m_NexusHP;

	int *currStruct;
};

