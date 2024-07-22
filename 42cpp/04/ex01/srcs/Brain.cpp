#include "../headers/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "I'm hungry i want to eat";
}

Brain::Brain( const Brain & src )
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this == &rhs )
		return *this;

	for(int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */