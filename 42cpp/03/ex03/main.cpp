#include "headers/ClapTrap.hpp"
#include "headers/FragTrap.hpp"
#include "headers/ScavTrap.hpp"
#include "headers/DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("john");

	diamond.highFivesGuys();
	diamond.attack("random name");
	diamond.beRepaired(3);
	diamond.guardGate();
	diamond.whoAmI();
	cout << diamond << std::endl;
	return 0;
}