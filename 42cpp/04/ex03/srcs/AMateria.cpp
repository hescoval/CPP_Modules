#include "../headers/AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria( const AMateria & src )
{
	this->_type = src.getType();
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria:: use(ICharacter& target)
{
	(void)target;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const string& AMateria :: getType() const
{
	return this->_type;
}


/* ************************************************************************** */