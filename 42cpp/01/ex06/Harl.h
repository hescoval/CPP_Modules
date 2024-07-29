#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

class Harl
{
	private:
		int		Ignore;
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		int		find_level( string level );
		void (Harl::*funcArray[4])(void);


	public:
		Harl();
		~Harl();
		void	complain(	);
		void	call_functions(	string level);
};