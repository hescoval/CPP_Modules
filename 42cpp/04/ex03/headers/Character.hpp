#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "general.hpp"

# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{
	public:

		Character(const string name = "Default Warrior");
		Character( Character const & src );
		~Character();

		string const & getName() const;
		void equip				(AMateria* m);
		void unequip			(int idx);
		void use				(int idx, ICharacter& target);
		AMateria*				inventory_peek(int idx);
		Character &				operator=( Character const & rhs );

	private:
		string _name;
		AMateria *_inventory[4];
};

#endif /* ******************************************************* CHARACTER_H */