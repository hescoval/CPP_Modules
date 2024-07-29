#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "general.hpp"

class ClapTrap
{
	private:
		string name;
		int hp;
		int ep;
		int ad;

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
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );
};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */