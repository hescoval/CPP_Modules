#include "../headers/WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	cout << RED "WrongCat is being created" RESET << endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original){}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	cout << RED "WrongCat is being ... sent to a better place" RESET << endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const
{
	cout << "Meow Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */