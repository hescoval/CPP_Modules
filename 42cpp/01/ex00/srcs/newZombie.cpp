#include "../headers/Zombie.h"

Zombie* newZombie( string name )
{
	Zombie* zed = new Zombie(name);
	return zed;
}