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
	cout << "I think I deserve to have some extra bacon for free.\n"
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

int	Harl::find_level( string level )
{
	for(long unsigned int i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);

	string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	int match = -1;

	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i])
			match = i;
	}
	
	return(match);
}

void Harl::complain( string level )
{
	int match = find_level(level);
	if(match == -1)
	{
		cout << "This is ridiculous! Im already overworked and you try "
			"and make me do more and more things. Get yourself together." << std::endl;
		return;
	}

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

	if(match < Ignore || Ignore == -1)
	{
		cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
		return;
	}
	cout << "[ " << levels[match] << " ]" << std::endl;
	(this->*funcArray[match])();
	cout << std::endl;
	return;
}

void Harl::set_ignore( string level )
{
	int match = find_level( level );

	switch(match)
	{
		case(0):
		{
			Ignore = 0;
			break;
		}
		case(1):
		{
			Ignore = 1;
			break;
		}
		case(2):
		{
			Ignore = 2;
			break;
		}
		case(3):
		{
			Ignore = 3;
			break;
		}
		default:
			Ignore = -1;
	}
}