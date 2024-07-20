#include "../headers/PhoneBook.h"

PhoneBook::PhoneBook()
{
	c_num = 0;
	existing_contacts = 0;
}

int	PhoneBook::get_n_contacts()
{
	return existing_contacts;
}

Contact	PhoneBook::get_contact(int i)
{
	if(i > 0 && i <= existing_contacts)
		return Contacts[i - 1];

	throw std::runtime_error("Invalid Index");
}

void	PhoneBook::add_contact(Contact add)
{
	if(c_num == 8)
		c_num = 0;
	if(existing_contacts < 8)
		existing_contacts++;
	Contacts[c_num++] = add;
}

Contact*	PhoneBook::fetch_contacts()
{
	if(existing_contacts == 0)
	{
		throw std::runtime_error("\nThere's currently nothing to display in the Phonebook.");
	}
	return Contacts;
}