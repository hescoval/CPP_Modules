#include "../headers/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(const string name)
{
	this->_name = name;

	for (int i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;
}

Character::Character( const Character & src )
{
	this->_name = src.getName();
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if(src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	cout << RED << this->_name << " is destroying all of his Materias and quitting on being an adventurer" RESET << endl;
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if(_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if(this == &rhs)
		return *this;
	this->_name = rhs.getName();
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if(rhs._inventory[i] != NULL)
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	for(int i = 0; i < MAX_SLOTS; i++)
	{
		if(_inventory[i] == m)
		{
			cout << this->_name << " already has this Materia equipped" << endl;
			return ;
		}

		if(_inventory[i] == NULL)
		{
			_inventory[i] = m;
			cout << this->_name << " has equipped a Materia of type -" << m->getType() << "-" << endl;
			return ;
		}
	}
	cout << this->_name << "'s Inventory's full, drop something to be able to equip it" << endl;
	return ;
}

void Character::unequip			(int idx)
{
	if(idx < 0 || idx >= MAX_SLOTS)
	{
		cout << RED "Invalid index" RESET << endl;
		return ;
	}
	if(_inventory[idx] == NULL)
	{
		cout << RED "Nothing to unequip" RESET << endl;
		return ;
	}
	cout << this->_name << " has unequipped a Materia of type -" << _inventory[idx]->getType() << "-" << endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx >= MAX_SLOTS)
	{
		cout << RED "Invalid index" RESET << endl;
		return ;
	}
	if(_inventory[idx] == NULL)
	{
		cout << RED "Nothing to use" RESET << endl;
		return ;
	}
	cout << BRIGHT_GREEN << this->_name << " is using a Materia of type -" << _inventory[idx]->getType() << "-" RESET << endl;
	_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string const& Character::getName() const
{
	return _name;
}

AMateria*				Character::inventory_peek(int idx)
{
	if(idx < 0 || idx >= MAX_SLOTS)
	{
		cout << "Invalid index" << endl;
		return NULL;
	}
	return _inventory[idx];
}

/* ************************************************************************** */