#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "general.hpp"
# include "Brain.hpp"

class Animal
{

	protected:
		string type;

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();
		virtual void makeSound() const;

		string getType() const;
		Animal &		operator=( Animal const & rhs );

	private:
};

#endif /* ********************************************************** ANIMAL_H */