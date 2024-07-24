#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "general.hpp"

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		string _type;

	public:
		AMateria(std::string const & type);
		AMateria( AMateria const & src );

		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif /* ******************************************************** AMATERIA_H */