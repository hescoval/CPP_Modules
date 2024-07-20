#include "../headers/Fixed.hpp"
#include "../headers/general.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed( const Fixed& src )
{
	cout << "Copy constructor called" << std::endl;
	this->number = src.getRawBits();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & original )
{
	cout << "Copy assignment operator called" << std::endl;
	if ( this != &original )
	{
		this->number = original.getRawBits();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << "Value = " << i.getRawBits();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR AND MUTATORS ---------------------------------
*/
int			Fixed::getRawBits( void ) const
{
	cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void		Fixed::setRawBits( int const raw )
{
	this->number = raw;
}

/* ************************************************************************** */