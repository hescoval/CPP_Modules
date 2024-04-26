#include "../headers/ContactMaker.h"
#include "../headers/utils.h"

string ContactMaker::get_input(string field, string error = "No contact field can be empty.")
{
	print_stuff(HEADER);
	string input = "";

	cout << "Enter the Contact's " << field << std::endl;
	std::getline(std::cin, input);
	trim(input);

	while(empty_string(input))
	{
		print_stuff(HEADER);
		cout << "You are inputting the contact's " << field << "\n" << std::endl;
		cout << error << std::endl;
		std::getline(std::cin, input);
		trim(input);
	}

	return input;
}

void ContactMaker::make_contact()
{
	Contact ret;

	ret.set_first(get_input("First Name"));
	ret.set_last(get_input("Last Name"));
	ret.set_nick(get_input("Nick Name"));
	ret.set_phone(get_input("Phone Number"));
	ret.set_darkest(get_input("Darkest Secret", "Come on, everyone has one."));

	user_pb.add_contact(ret);
}

void	ContactMaker::list_contacts()
{
	Contact curr;
	Contact *to_print;
	int	total_contacts = user_pb.get_n_contacts();

	try
	{
		to_print = user_pb.fetch_contacts();
	}
	catch(const std::exception& e)
	{
		cout << e.what() << std::endl;
		sleep(3);
		return;
	}

	for(int i = 0; i < total_contacts; i++)
	{
		curr = to_print[i];
		print_ws();
		cout << "|";
		print_field(i_to_s(i + 1));
		print_field(curr.get_first());
		print_field(curr.get_last());
		print_field(curr.get_nick());
		cout << std::endl;
		print_bpad();
	}
}

void ContactMaker::search()
{
	Contact to_print;
	string input;

	print_stuff(TABLE);
	list_contacts();
	cout << "\nWhat entry do you want to look at?" << std::endl;
	std::getline(std::cin, input);
	trim(input);

	while(!fully_numeric(input))
	{
		print_stuff(TABLE);
		list_contacts();
		cout << "\nPlease numbers only (1 - 8)" << std::endl;
		std::getline(std::cin, input);
		trim(input);
	}

	int num = std::atoi(input.data());
	try
	{
		to_print = user_pb.get_contact(num);
	}
	catch(const std::exception& e)
	{
		std::cout << '\n' << e.what() << '\n';
		sleep(3);
		return;
	}
	print_contact(to_print);
}