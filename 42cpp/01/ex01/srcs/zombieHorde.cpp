#include "../headers/Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	if(horde == NULL)
		throw std::bad_alloc();

	for(int i = 0; i < N; i++)
		horde[i].set_name(name);
	
	return horde;
}