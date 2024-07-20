#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "general.hpp"

class WrongAnimal
{

	protected:
		string type;

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();
		void makeSound() const;

		string getType() const;
		WrongAnimal &		operator=( WrongAnimal const & rhs );

	private:
};

#endif /* ********************************************************** WRONGANIMAL_H */