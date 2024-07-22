#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "general.hpp"

class Brain
{
	public:
		string ideas[100];

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

	private:
};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */