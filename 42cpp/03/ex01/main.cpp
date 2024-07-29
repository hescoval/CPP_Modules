#include "headers/ClapTrap.hpp"
#include "headers/ScavTrap.hpp"

int main()
{
	ScavTrap scav("test scav");

	cout << scav << std::endl;
	scav.attack("random name");
	scav.beRepaired(3);
	scav.guardGate();
	cout << scav << std::endl;

	// Barrage of attacks
	while(scav.getEp() > 0)
		scav.attack("random name");
		
	scav.attack("random name");
	
	cout << scav << std::endl;
	return 0;
}