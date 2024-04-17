#include "Zombie.h"


void Zombie::announce()
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

string Zombie::get_name()
{
	return name;
}

Zombie::Zombie(string new_name)
{
	name = new_name;
}

Zombie::~Zombie()
{
	cout << name << " Has been painlessly killed" << std::endl;
}