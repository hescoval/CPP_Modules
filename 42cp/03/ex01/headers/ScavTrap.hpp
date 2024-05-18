#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const ScavTrap& trap);
		ScavTrap();
		ScavTrap(string new_name);
		void 	guardGate();
		virtual ~ScavTrap();
		void attack(const string& target);


	ScavTrap &			operator=( ScavTrap const & rhs );
};

#endif /* ******************************************************** SCAVTRAP_H */