#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const FragTrap& trap);
		FragTrap();
		FragTrap(string new_name);
		void 	highFivesGuys();
		virtual ~FragTrap();
		void 	attack(const string& target);


	FragTrap &			operator=( FragTrap const & rhs );
};

#endif /* ******************************************************** FRAGTRAP_H */