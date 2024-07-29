#include "headers/Zombie.h"

int main()
{
	Zombie* test = newZombie("Generic Zombie Name, but dynamically allocated");
	Zombie Another("Generic Zombie Name, but on the Stack");

	randomChump("Background Zombie");

	test->announce();
	Another.announce();
	delete test;
}