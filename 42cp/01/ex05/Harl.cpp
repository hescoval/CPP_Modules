#include "Harl.h"

void Harl::debug( void )
{
	cout << "I love having extra bacon"
			" for my 7XL-double-cheese-triple-pickle-specialketchup burger."
			" I really do!" << std::endl;
}

void Harl::info( void )
{
	cout <<  "I cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger! "
	"If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	cout << "I think I deserve to have some extra bacon for free. "
			"I've been coming for years whereas you started working "
			"here since last month." << std::endl;
}

void Harl::error( void )
{
	cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	Ignore = -1;
}

Harl::~Harl()
{

}

void Harl::complain( string level )
{
	for(long unsigned int i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);

	void (Harl::*funcArray[4])() = 
	{ 
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error 
	};

	string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*funcArray[i])();
			return;
		}
	}

	cout << "This is ridiculous! Im already overworked and you try "
			"and make me do more and more things. Get yourself together." << std::endl;
}