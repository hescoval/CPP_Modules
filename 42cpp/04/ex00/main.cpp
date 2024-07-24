#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/WrongAnimal.hpp"
#include "headers/WrongCat.hpp"
#include <limits>

void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongCat2 = new WrongCat();

	enter_to_continue();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	wrong->makeSound();
	wrongCat->makeSound();
	wrongCat2->makeSound();

	enter_to_continue();

	delete j; // dog
	delete i; // cat
	delete wrong; // base class
	delete wrongCat;
	delete wrongCat2;
	delete meta; // base class
}