#include "../headers/MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for(int i = 0; i < MAX_SLOTS ; i++)
		_LearnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		if(src._LearnedMaterias[i] != NULL)
			_LearnedMaterias[i] = src._LearnedMaterias[i]->clone();
		else
			_LearnedMaterias[i] = NULL;
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	cout << RED "MateriaSource is being destroyed" RESET << endl;
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		if(_LearnedMaterias[i] != NULL)
		{
			delete _LearnedMaterias[i];
			_LearnedMaterias[i] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for(int i = 0; i < MAX_SLOTS; i++)
		{
			if(rhs._LearnedMaterias[i] != NULL)
			{
				delete _LearnedMaterias[i];
				_LearnedMaterias[i] = rhs._LearnedMaterias[i]->clone();
			}
			else
				_LearnedMaterias[i] = NULL;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void 				MateriaSource::learnMateria(AMateria* new_materia)
{
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		if(_LearnedMaterias[i] == NULL)
		{
			_LearnedMaterias[i] = new_materia;
			return;
		}
	}
}

AMateria*			MateriaSource::createMateria(string const & type)
{
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		if(_LearnedMaterias[i] != NULL && _LearnedMaterias[i]->getType() == type)
			return _LearnedMaterias[i]->clone();
	}

	cout << BOLD RED "MateriaSource does not know this type of materia" RESET << endl;
	return 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */