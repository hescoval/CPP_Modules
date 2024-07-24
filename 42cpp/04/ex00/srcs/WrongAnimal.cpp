#include "../headers/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	cout << RED "WrongAnimal (PARENT CLASS) is being created" RESET << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	this->type = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	cout << RED "WrongAnimal (PARENT CLASS) is being destroyed" RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

string WrongAnimal::getType() const
{
	return this->type;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */