#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "general.hpp"

# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif


class ClapTrap
{
	protected:
		int hp;
		int ep;
		int ad;
		string name;

	public:
		string getName() const;
		int getHp() const;
		int getEp() const;
		int getAd() const;

		void attack(const string& target);
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount);
		
		ClapTrap();
		ClapTrap(string new_name);
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );
};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */