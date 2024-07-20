#include "Harl.h"

int main()
{
	Harl machine;

	string complaints[4] =
	{
		"warning",
		"dEBug",
		"error",
		"info"
	};

	for(int i = 0; i < 4; i++)
	{
		machine.complain(complaints[i]);
		cout << "\n";
	}

	machine.complain("what");
}