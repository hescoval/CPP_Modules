#include "../headers/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	cout << GREEN "A cute little puppy has showed up!" << endl;
	this->type = "Dog";
	this->brain = new Brain();
}


Dog::Dog(const Dog &original) : Animal(original)
{
	this->brain = new Brain(*original.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->brain;
	cout << RED "Dog is being ... sent to a better place" RESET << endl;
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