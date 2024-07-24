#include "../headers/Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice"){}


Ice::Ice( const Ice & src ) : AMateria(src){}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	cout << BRIGHT_CYAN "* shoots an ice bolt at " << target.getName() << " *" RESET << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */