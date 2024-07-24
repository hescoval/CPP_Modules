#include "../headers/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	cout << GREEN "An evil evil cat has been born!" RESET << endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &original) : Animal(original)
{
	this->brain = new Brain(*original.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->brain;
	cout << RED "Cat is being ... sent to a better place" RESET << endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this == &rhs )
		return *this;

	Brain* newBrain = new Brain(*rhs.brain);
	delete this->brain;
	this->brain = newBrain;
	return *this;
}

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

Brain* Cat::getBrain() const
{
	return this->brain;
}

/* ************************************************************************** */