#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;

class Harl
{
	private:
		int		Ignore;
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		int		find_level( string level );

	public:
		Harl();
		~Harl();
		void	complain( string level );
		void	set_ignore(	string level);
};