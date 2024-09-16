#include "../headers/MutantStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


MutantStack::MutantStack(){}

MutantStack::MutantStack( const MutantStack & src )
{
	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MutantStack::~MutantStack(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MutantStack &				MutantStack::operator=( MutantStack const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

MutantStack::iterator	MutantStack::begin()
{
	return this->c.begin();
}

MutantStack::iterator	MutantStack::end()
{
	return this->c.end();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */