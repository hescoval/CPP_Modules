#include "../headers/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	cout << GREEN "A cute little puppy has showed up!" << endl;
	this->type = "Dog";
}


Dog::Dog(const Dog &original) : Animal(original){}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	cout << RED "Dog is being ... sent to a better place" RESET << endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	cout << "Bark Bark" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */