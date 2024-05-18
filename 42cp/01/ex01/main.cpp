#include "Zombie.h"

int bug(string str)
{
	cout << str << std::endl;
	return 1;
}

int main(int ac, char **av)
{
	if(ac != 2)
		return bug("Error: wrong number of arguments\nUsage: ./Zombie \"name\"");
	string name(av[1]);

	int n_z = 5;
	Zombie* horde = zombieHorde(n_z, name);

	for(int i = 0; i < n_z; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}