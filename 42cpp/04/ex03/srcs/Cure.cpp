#include "../headers/Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure"){}


Cure::Cure( const Cure & src ) : AMateria(src){}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	cout << GREEN "* Heals " << target.getName() << "'s wounds *" RESET <<  endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */