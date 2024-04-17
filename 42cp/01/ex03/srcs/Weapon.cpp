#include "../headers/Weapon.h"

Weapon::Weapon(string new_Type)
{
	type = new_Type;
}

const string& Weapon::getType()
{
	return type;
}

void	Weapon::setType(string new_type)
{
	type = new_type;
}