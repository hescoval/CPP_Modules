#include "../headers/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
}


Dog::Dog(const Dog &original) : Animal(original){}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this == &rhs )
		return *this;

	delete this->brain;
	this->brain = new Brain(*rhs.brain);
	return *this;
}

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

Brain* Dog::getBrain() const
{
	return this->brain;
}

/* ************************************************************************** */