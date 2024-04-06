#include "../headers/PhoneBook.h"
#include "../headers/utils.h"

PhoneBook::PhoneBook()
{
	c_num = 0;
	existing_contacts = 0;
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

void	PhoneBook::list_and_find_contact()
{
	print_stuff(TABLE);
	if(existing_contacts == 0)
	{
		throw std::runtime_error("\nThere's currently nothing to display in the Phonebook.");
	}

	Contact curr;
	
	for(int i = 0; i < existing_contacts; i++)
	{
		curr = Contacts[i];
		print_ws();
		cout << "|";
		print_field(i_to_s(i + 1));
		print_field(curr.first_name);
		print_field(curr.last_name);
		print_field(curr.nick_name);
		cout << std::endl;
		print_bpad();
	}
}