#include "../headers/Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer(){}

Serializer::Serializer( const Serializer & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t	Serializer::serialize(Data *raw)
{
	return reinterpret_cast<uintptr_t>(raw);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */