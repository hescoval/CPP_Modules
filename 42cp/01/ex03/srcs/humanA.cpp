#include "../headers/HumanA.h"

/*
	References must be initalized with a list as they cannot be NULL
*/

HumanA::HumanA(string new_name, Weapon& Wielding) : Armed_With(Wielding)
{
	name = new_name;
}

void HumanA::attack()
{
	const string& weapon_reference = Armed_With.getType();

	cout << name << " swings his " << weapon_reference << " With extreme force!" << std::endl;
}

void HumanA::setWeapon(Weapon new_weapon)
{
	Armed_With = new_weapon;
}