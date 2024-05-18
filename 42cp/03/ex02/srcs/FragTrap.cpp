#include "../headers/FragTrap.hpp"
#include "../headers/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	LOG("FragTrap Default constructor has been called");
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	LOG("FragTrap Copy constructor has been called");
}

FragTrap::FragTrap(string new_name) : ClapTrap(new_name)
{
	LOG("FragTrap Parametric constructor has been called");
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	LOG("FragTrap Default destructor has been called");
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
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

void FragTrap::attack(const string& target)
{
	if(this->ep <= 0 || this->hp <= 0)
	{
		cout << "Fragtrap " << this->name << " is out of Energy Points (" << this->ep << ") or out of Health Point(s) (" << this->hp << ")" << std::endl;
		return;
	}
	this->ep -= 1;
	cout << "The Frag trap " << this->name << " is attacking " << target << " and causing " << this->ad << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys()
{
	cout << this->name << " patiently waited for someone to High Five him and got one!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */