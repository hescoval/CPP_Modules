#include "Zombie.h"

int main()
{
	Zombie* test = new Zombie("Generic Zombie Name, but dynamically allocated");
	Zombie Another("Generic Zombie Name, but on the Stack");

	test->announce();
	Another.announce();
	delete test;
}