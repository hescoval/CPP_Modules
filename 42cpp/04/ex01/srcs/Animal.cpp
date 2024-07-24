#include "../headers/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	cout << GREEN "Animal (PARENT CLASS) has been born" RESET << endl;
	this->type = "Animal";
}

Animal::Animal( const Animal & src )
{
	this->type = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	cout << GREEN "Animal (PARENT CLASS) is being destroyed" RESET << endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
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

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string Animal::getType() const
{
	return this->type;
}

/* ************************************************************************** */