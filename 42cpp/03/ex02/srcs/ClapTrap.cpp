#include "../headers/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	LOG(GREEN "Claptrap Default constructor has been called" RESET);
	this->name = "John Doe";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
}

ClapTrap::ClapTrap(string new_name)
{
	LOG(GREEN "ClapTrap Parametric constructor has been called" RESET);
	this->name = new_name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
}

ClapTrap::ClapTrap( const ClapTrap & rhs )
{
	LOG(GREEN "ClapTrap Copy constructor has been called" RESET);
	this->name = rhs.getName();
	this->ad = rhs.getAd();
	this->hp = rhs.getHp();
	this->ep = rhs.getEp();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	cout << RED "Default destructor has been called" RESET << std::endl;
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->ad = rhs.ad;
		this->hp = rhs.hp;
		this->ep = rhs.ep;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "\nTrap: " << i.getName() << std::endl;
	o << "\tHealth Points : " << i.getHp() << std::endl;
	o << "\tEnergy Points : " << i.getEp() << std::endl;
	o << "\tAttack Damage : " << i.getAd() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
	void ClapTrap::attack(const string& target)
	{
		if(this->ep <= 0 || this->hp <= 0)
		{
			cout << this->name << " is out of Energy Points (" << this->ep << ") or out of Health Point(s) (" << this->hp << ")" << std::endl;
			return;
		}
		this->ep -= 1;
		cout << this->name << " is attacking " << target << " and causing " << this->ad << " points of damage" << std::endl;
	}

	void ClapTrap::beRepaired(unsigned int amount)
	{
		if(this->ep < 0)
		{
			cout << this->name << " is out of Energy Points" << std::endl;
			return;
		}

		this->ep -= 1;
		cout << this->name << " is being repaired and gained " << amount << " Health Point(s)" << std::endl;
		this->hp += amount;
		cout << this->name << " has " << this->hp << " Health Point(s) now" << std::endl;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	void ClapTrap::takeDamage(unsigned int amount)
	{
		if(this->hp < 0)
		{
			cout << this->name << " is out of Health Point(s)" << std::endl;
			return;
		}

		cout << this->name << " is taking damage and lost " << amount << " Health Point(s)" << std::endl;
		this->hp -= amount;
		cout << this->name << " has " << this->hp << " Health Point(s)" << std::endl;
	}

	string ClapTrap::getName() const
	{
		return this->name;
	}

	int ClapTrap::getHp() const
	{
		return this->hp;
	}

	int ClapTrap::getEp() const
	{
		return this->ep;
	}

	int ClapTrap::getAd() const
	{
		return this->ad;
	}
/* ************************************************************************** */