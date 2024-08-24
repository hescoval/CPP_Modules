#include <iostream>
#include "headers/Fixed.hpp"
#include "headers/general.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	Fixed small(a);

	Fixed big(b);

	cout << "\n---------Comparison operator test---------\n" << endl;

	cout << "small = " << small << endl;
	cout << "big = " << big << endl;

	cout << "small < big = " << (small < big) << endl;
	cout << "small > big = " << (small > big) << endl;
	cout << "small <= big = " << (small <= big) << endl;
	cout << "small >= big = " << (small >= big) << endl;
	cout << "small == big = " << (small == big) << endl;
	cout << "small != big = " << (small != big) << endl;

	cout << "\n---------Arithmetic operator test---------\n" << endl;

	cout << "small + big = " << (small + big) << endl;
	cout << "small - big = " << (small - big) << endl;
	cout << "small * big = " << (small * big) << endl;
	cout << "small / big = " << (small / big) << endl;

	cout << "\n---------Increment and Decrement operator test---------\n" << endl;

	cout << "small = " << small << endl;
	cout << "small++ = " << small++ << endl;
	cout << "small = " << small << endl;
	cout << "++small = " << ++small << endl;
	cout << "small = " << small << endl;
	cout << "small-- = " << small-- << endl;
	cout << "small = " << small << endl;
	cout << "--small = " << --small << endl;
	cout << "small = " << small << endl;
	
	cout << "\n---------Min and Max test---------\n" << endl;

	cout << "small = " << small << endl;
	cout << "big = " << big << endl;
	cout << "Fixed::min(small, big) = " << Fixed::min(small, big) << endl;
	cout << "Fixed::max(small, big) = " << Fixed::max(small, big) << endl;

	cout << "\n---------Destructors---------\n" << endl;
	return 0;
}

