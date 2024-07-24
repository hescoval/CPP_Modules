#include "../headers/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	cout << GREEN "An evil evil cat has been born!" RESET << endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &original) : Animal(original){}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	cout << RED "Cat is being ... sent to a better place" RESET << endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	cout << "Meow Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */