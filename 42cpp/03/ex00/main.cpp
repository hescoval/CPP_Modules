#include "headers/ClapTrap.hpp"

bool error_handle(int ac)
{
	if(ac != 3)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "\nUsage: ./ClapTrap \"name1\" \"name2\"\n" << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char **av)
{
	if(!error_handle(ac))
	{
		return 1;
	}

	ClapTrap claptrap(av[1]);
	ClapTrap claptrap2(av[2]);
	ClapTrap two_copy(claptrap2);
	ClapTrap default_claptrap;

	claptrap.attack(claptrap2.getName());
	claptrap2.takeDamage(111);

	// ostream and repair tests

	cout << claptrap2 << std::endl;
	claptrap2.beRepaired(102);
	cout << claptrap2 << std::endl;

	cout << default_claptrap << std::endl;


	return 0;
}