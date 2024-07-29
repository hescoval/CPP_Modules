#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

int main()
{
	Cat* j = new Cat();
	Cat* i = new Cat(*j);
	Cat* k = new Cat();

	*k = *j;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	cout << "Brain of j " << j->getBrain() << endl;
	cout << "Brain of i " << i->getBrain() << endl;
	cout << "Brain of k " << k->getBrain() << endl;

	delete k;
	delete j;
	delete i;
}