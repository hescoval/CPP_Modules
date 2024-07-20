#include "Harl.h"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		cout << "Incorrect Usage!\n ./(program name) (desired level)" << std::endl;
		return 1;
	}

	Harl machine;
	machine.call_functions(string(av[1]));
}