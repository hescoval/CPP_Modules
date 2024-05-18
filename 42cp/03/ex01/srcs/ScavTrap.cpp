#include "../headers/ScavTrap.hpp"
#include "../headers/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	LOG("ScavTrap Default constructor has been called");
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	LOG("ScavTrap Copy constructor has been called");
}

ScavTrap::ScavTrap(string new_name) : ClapTrap(new_name)
{
	LOG("ScavTrap Parametric constructor has been called");
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	LOG("ScavTrap Default destructor has been called");
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->ad = rhs.getAd();
		this->hp = rhs.getHp();
		this->ep = rhs.getEp();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const string& target)
{
	if(this->ep <= 0 || this->hp <= 0)
	{
		cout << "Gosh darnit, " << this->name << " is out of Energy Points (" << this->ep << ") or out of Health Point(s) (" << this->hp << ")" << std::endl;
		return;
	}
	this->ep -= 1;
	cout << "The rusty outlaw " << this->name << " is attacking " << target << " and causing " << this->ad << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	cout << this->name << " has entered in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */