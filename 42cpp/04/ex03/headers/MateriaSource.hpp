#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		void 				learnMateria(AMateria*);
		AMateria*			createMateria(string const & type);
		MateriaSource &		operator=( MateriaSource const & rhs );

	private:
		AMateria* _LearnedMaterias[4];

};
#endif /* *************************************************** MATERIASOURCE_H */