#ifndef CURE_HPP
# define CURE_HPP

# include "general.hpp"

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );
		AMateria 	*clone() const;
		void		use(ICharacter &target);
};

#endif /* ************************************************************ CURE_H */