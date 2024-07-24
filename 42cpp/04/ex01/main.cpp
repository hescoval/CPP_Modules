#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

int main()
{
	Dog basic;
	{
		Animal *newDog = new Dog(basic);
		delete newDog;
		Dog tmp = basic;
	}

	cout << basic.getBrain() << endl;
}