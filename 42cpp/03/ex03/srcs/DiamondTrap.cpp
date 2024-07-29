#include "../headers/DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap("default_clap_name"), FragTrap("default_clap_name")
{
	LOG(GREEN"DiamondTrap Default constructor has been called"RESET);
	this->name = "default";
	this->FragTrap::hp = 100;
	this->ScavTrap::ep = 50;
	this->FragTrap::ad = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src.getDName() + "_clap_name"), ScavTrap(src.getDName() + "_clap_name"), FragTrap(src.getDName() + "_clap_name")
{
	LOG(GREEN"DiamondTrap Copy constructor has been called"RESET);
	if (this == &src)
		return ;
	this->name = src.getDName();
	this->FragTrap::ad = src.FragTrap::getAd();
	this->FragTrap::hp = src.FragTrap::getHp();
	this->ScavTrap::ep = src.ScavTrap::getEp();
}

DiamondTrap::DiamondTrap(string new_name) : ClapTrap(new_name + "_clap_name"), ScavTrap(new_name + "_clap_name"), FragTrap(new_name + "_clap_name")
{
	LOG(GREEN"DiamondTrap Parametric constructor has been called"RESET);
	this->DiamondTrap::name = new_name;
	this->FragTrap::hp = 100;
	this->ScavTrap::ep = 50;
	this->FragTrap::ad = 30;
}

DiamondTrap::~DiamondTrap()
{
	LOG(RED"DiamondTrap Default destructor has been called"RESET);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getDName();
		this->FragTrap::ad = rhs.FragTrap::getAd();
		this->FragTrap::hp = rhs.FragTrap::getHp();
		this->ScavTrap::ep = rhs.ScavTrap::getEp();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

string DiamondTrap::getDName() const
{
	return this->name;
}

void DiamondTrap::attack(const string& target)
{
	this->FragTrap::attack(target);
	this->ScavTrap::ep -= 1;
}

void	DiamondTrap::whoAmI()
{
	cout << "I am " << this->name << " and my ClapTrap name is " << this->ScavTrap::getName() << std::endl;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << "\nTrap: " << i.getDName() << std::endl;
	o << "\tHealth Points : " << i.FragTrap::getHp() << std::endl;
	o << "\tEnergy Points : " << i.ScavTrap::getEp() << std::endl;
	o << "\tAttack Damage : " << i.FragTrap::getAd() << std::endl;
	return o;
}

/* ************************************************************************** */