#include "../headers/FragTrap.hpp"
#include "../headers/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	LOG(GREEN"Trap Default constructor has been called"RESET);
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	LOG(GREEN"Trap Copy constructor has been called"RESET);
}

FragTrap::FragTrap(string new_name) : ClapTrap(new_name)
{
	LOG(GREEN"Trap Parametric constructor has been called"RESET);
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	LOG(RED"Trap Default destructor has been called"RESET);
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