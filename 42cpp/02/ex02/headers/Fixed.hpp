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
		Fixed( const int input);
		Fixed( const float input);
		Fixed( Fixed const& src );
		~Fixed();

		/************	 	Overloads 		***********/
		bool		operator>(Fixed const& original);
		bool		operator>=( Fixed const& original );
		bool		operator<(Fixed const& original);
		bool		operator<=( Fixed const& original );
		bool		operator==(Fixed const& original);
		bool		operator!=(Fixed const& original);

		Fixed&		operator=( Fixed const& original );
		Fixed		operator+( Fixed const& original );
		Fixed		operator++( int );
		Fixed&		operator++();
		Fixed		operator-( Fixed const& original );
		Fixed		operator--( int );
		Fixed&		operator--();
		Fixed		operator*( Fixed const& original );
		Fixed		operator/( Fixed const& original );

		/**********************************************/
		static Fixed&			min(Fixed &a, Fixed &b);
		static Fixed&			max(Fixed &a, Fixed &b);
		static const Fixed&		min(Fixed const &a, Fixed const &b);
		static const Fixed&		max(Fixed const &a, Fixed const &b);

		int			getRawBits( void ) const ;
		void		setRawBits( int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

std::ostream &			operator<<( std::ostream& o, Fixed const& i );

#endif /* *********************************************************** FIXED_H */