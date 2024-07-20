#include "../headers/Contact.h"
#include "../headers/general.h"

string Contact::get_first()
{
	return first_name;
}

string Contact::get_last()
{
	return last_name;
}

string Contact::get_nick()
{
	return nick_name;
}

string Contact::get_phone()
{
	return phone;
}

string Contact::get_darkest()
{
	return darkest_secret;
}

void	Contact::set_first(string input)
{
	first_name = input;
}

void	Contact::set_last(string input)
{
	last_name = input;
}

void	Contact::set_nick(string input)
{
	nick_name = input;
}

void	Contact::set_phone(string input)
{
	phone = input;
}

void	Contact::set_darkest(string input)
{
	darkest_secret = input;
}