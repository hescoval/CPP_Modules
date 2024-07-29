#include "headers/Zombie.h"

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

	int n_z = __INT_MAX__;
	try
	{
		Zombie* horde = zombieHorde(n_z, name);

		for(int i = 0; i < n_z; i++)
			horde[i].announce();

		delete[] horde;
	}
	catch(const std::bad_alloc& e)
	{
		cout << "Error: Couldn't allocate zombie horde" << std::endl;
		return 1;
	}
}