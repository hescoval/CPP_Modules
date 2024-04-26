#include "Harl.h"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		cout << "Incorrect Usage!\n ./(program name) (desired level)" << std::endl;
		return 1;
	}

	Harl machine;
	machine.set_ignore(string(av[1]));
	
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
	}

	machine.complain("what");
}