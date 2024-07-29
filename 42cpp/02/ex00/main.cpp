#include <iostream>
#include "headers/Fixed.hpp"
#include "headers/general.hpp"


int main()
{
	// No value swapping
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	cout << "\n--------------------------------\n" << endl;
	// Value swapping
	{
		Fixed a;
		a.setRawBits ( 42 );
		Fixed b( a );
		Fixed c;
		c = b;


		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	return 0;
}