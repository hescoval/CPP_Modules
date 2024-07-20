#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int number;
		const static int frac_bits = 8;

	public:

		Fixed();
		Fixed( Fixed const& src );
		~Fixed();

		Fixed &		operator=( Fixed const& original );
		int			getRawBits( void ) const ;
		void		setRawBits( int const raw);
};

std::ostream &			operator<<( std::ostream& o, Fixed const& i );

#endif /* *********************************************************** FIXED_H */