#include "Harl.h"

void Harl::debug( void )
{
	cout << "[  DEBUG  ] " << std::endl;
	cout << "I love having extra bacon"
			" for my 7XL-double-cheese-triple-pickle-specialketchup burger."
			" I really do!" << std::endl;
}

void Harl::info( void )
{
	cout << "[  INFO  ] " << std::endl;
	cout <<  "I cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger! "
	"If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	cout << "[  WARNING  ] " << std::endl;
	cout << "I think I deserve to have some extra bacon for free.\n"
			"I've been coming for years whereas you started working "
			"here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	cout << "[  ERROR  ] " << std::endl;
	cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

Harl::Harl()
{
	Ignore = -1;
    funcArray[0] = &Harl::debug;
    funcArray[1] = &Harl::info;
    funcArray[2] = &Harl::warning;
    funcArray[3] = &Harl::error;
}

Harl::~Harl()
{

}

int	Harl::find_level( string level )
{
	for(long unsigned int i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);

	int match = -1;

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
			match = i;
	}

	return(match);
}

void Harl::complain( )
{
	if(Ignore == -1)
	{
		cout << "This is ridiculous! Im already overworked and you try "
				"and make me do more and more things. Get yourself together." << std::endl;
		return;
	}

	return;
}

void Harl::call_functions( string level )
{
	int match = find_level( level );

	if(match < 0 || match > 3)
	{
		this->complain();
		return;
	}
	else
		Ignore = match;

	switch(match)
	{
		case(ERROR):
			(this->*funcArray[ERROR])();
		case(WARNING):
			(this->*funcArray[WARNING])();
		case(INFO):
			(this->*funcArray[INFO])();
		case(DEBUG):
			(this->*funcArray[DEBUG])();
		default:
		{
			break;
		}
	}
}