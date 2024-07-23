#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"

void first_main()
{
	//If you uncomment the line below this it won't compile
	//const Animal* wrong = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete j;
	delete i;
}

int main()
{
	Cat* j = new Cat();
	Cat* i = new Cat(*j);
	Cat* k = new Cat();
	*k = *j;

	first_main();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	cout << "Brain of j " << j->getBrain() << endl;
	cout << "Brain of i " << i->getBrain() << endl;
	cout << "Brain of k " << k->getBrain() << endl;

	delete k;
	delete j;
	delete i;
}