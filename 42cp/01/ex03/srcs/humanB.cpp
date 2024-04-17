#include "../headers/HumanB.h"

HumanB::HumanB(string new_name)
{
	name = new_name;
	Armed_With = NULL;
}

void HumanB::attack()
{
	if(Armed_With == NULL)
	{
		cout << name << " Wildly swings his fists around for some reason, its not pretty, he might die." << std::endl;
		return;
	}

	cout << name << " swings his " << Armed_With->getType() << " With extreme force!" << std::endl;
}

void HumanB::setWeapon(Weapon& new_weapon)
{
	Armed_With = &new_weapon;
}