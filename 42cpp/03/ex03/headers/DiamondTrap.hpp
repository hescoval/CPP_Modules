#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

# include <iostream>
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{

	private:
		string name;

	public:
		DiamondTrap(string new_name);
		DiamondTrap();
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();
		string 	getDName() const;
		void 	attack(const string& target);
		void	whoAmI();

		DiamondTrap &		operator=( DiamondTrap const & rhs );
};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );
#endif /* ***************************************************** DIAMONDTRAP_H */