#include "headers/ClapTrap.hpp"
#include "headers/FragTrap.hpp"

int main()
{
	FragTrap frag("test frag");

	cout << frag << std::endl;
	frag.attack("random name");
	frag.beRepaired(3);
	frag.highFivesGuys();
	cout << frag << std::endl;

	// Barrage of attacks
	// while(frag.getEp() > 0)
	// {
	// 	frag.attack("random name");
	// }
	// frag.attack("random name");
	// cout << frag << std::endl;

	return 0;
}