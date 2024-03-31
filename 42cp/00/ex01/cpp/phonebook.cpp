#include "../headers/PhoneBook.h"
#include "../headers/utils.h"

PhoneBook::PhoneBook()
{
	c_num = 0;
	existing_contacts = 0;
}

Contact PhoneBook::get_contact(int i)
{
	if(c_num == 0)
		throw std::runtime_error("No Contacts Yet");
	if(i >= 0 && i < c_num)
		return Contacts[i];

	throw std::runtime_error("Invalid Index");
}

void	PhoneBook::add_contact(Contact add)
{
	if(c_num == 7)
		c_num = 0;
	if(existing_contacts < 8)
		existing_contacts++;
	Contacts[c_num++] = add;
}

Contact	PhoneBook::list_and_find_contact()
{
	print_stuff(HEADER);
	print_table_header();
	if(existing_contacts == 0)
	{
		cout << "\n There's nothing to display! Press ANYTHING to continue." << std::endl;
		std::cin.get();
		throw std::runtime_error("");
	}

	Contact curr;
	
	for(int i = 0; i < existing_contacts; i++)
	{
		curr = Contacts[i];
		print_stuff(WS_LINE);
		cout << "|";
		print_field(i_to_s(i + 1));
		print_field(curr.first_name);
		print_field(curr.last_name);
		print_field(curr.nick_name);
		cout << std::endl;
		print_stuff(B_PAD);
	}

	cout << "\nWhat entry do you want to look at?" << std::endl;
	string input;
	std::getline(std::cin, input);
	int num = std::atoi(input.data());

	while(num < 0 || num >= existing_contacts)
	{
		std::getline(std::cin, input);
		num = std::atoi(input.data());
	}

	return get_contact(num);
}