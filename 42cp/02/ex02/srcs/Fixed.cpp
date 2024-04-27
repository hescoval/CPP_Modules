#include "../headers/Fixed.hpp"
#include "../headers/general.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(const int input)
{
	//cout << "Int constructor called" << std::endl;
	this->number = input << frac_bits;
}

Fixed::Fixed(const float input)
{
	//cout << "Float constructor called" << std::endl;
	this->number = roundf(input * (1 << frac_bits));

	// 1 < frac_bits == 2 to the power of frac_bits
}

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed( const Fixed& src )
{
	//cout << "Copy constructor called" << std::endl;
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
** --------------------------------- OVERLOADS ---------------------------------
*/


bool		Fixed::operator>=(Fixed const& right)
{
	return (this->number >= right.getRawBits());
}

bool		Fixed::operator<=(Fixed const& right)
{
	return (this->number <= right.getRawBits());
}

bool		Fixed::operator!=(Fixed const& right)
{
	return (this->number != right.getRawBits());
}

bool 		Fixed::operator==(Fixed const& right)
{
	return (this->number == right.getRawBits());
}

bool		Fixed::operator<(Fixed const& right)
{
	return (this->number < right.getRawBits());
}

bool		Fixed::operator>(Fixed const& right)
{
	return (this->number > right.getRawBits());
}

Fixed		Fixed::operator--(int)
{
	Fixed temp(*this);
	this->number--;
	return temp;
}

Fixed&		Fixed::operator--(void)
{
	this->number--;
	return *this;
}

Fixed&		Fixed::operator++(void)
{
	this->number++;
	return *this;
}

Fixed		Fixed::operator++(int)
{
	Fixed temp(*this);
	this->number++;
	return temp;
}

Fixed		Fixed::operator/(Fixed const& right)
{
	return Fixed(this->toFloat() / right.toFloat());
}

Fixed		Fixed::operator*(Fixed const& right)
{
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed		Fixed::operator-(Fixed const& right)
{
	return Fixed(this->toFloat() - right.toFloat());
}

Fixed		Fixed::operator+( Fixed const & right )
{
	return Fixed(this->toFloat() + right.toFloat());
}

Fixed&				Fixed::operator=( Fixed const & original )
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
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed&			Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;

}

Fixed&			Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;

}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}


int		Fixed::toInt(void) const
{
	return (this->number >> (frac_bits));
}

float	Fixed::toFloat(void) const
{
	float return_value;
	return_value = (float)this->number / (1 << frac_bits);

	return (return_value);
}

/*
** --------------------------------- ACCESSOR AND MUTATORS ---------------------------------
*/

int			Fixed::getRawBits( void ) const
{
	//cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void		Fixed::setRawBits( int const raw )
{
	this->number = raw;
}

/* ************************************************************************** */