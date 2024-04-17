#include "Zombie.h"

int main(int ac, char **av)
{
	if(ac != 2)
		return 0;
	string name(av[1]);

	int n_z = 5;
	Zombie* horde = zombieHorde(n_z, name);

	for(int i = 0; i < n_z; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}