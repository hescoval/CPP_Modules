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
		cout << error << std::endl;
		std::getline(std::cin, input);
		trim(input);
	}

	return input;
}

void ContactMaker::make_contact()
{
	Contact ret;

	ret.first_name = get_input("First Name");
	ret.last_name = get_input("Last Name");
	ret.nick_name = get_input("Nick Name");
	ret.phone = get_input("Phone Number");
	ret.darkest_secret = get_input("Darkest Secret", "Come on, everyone has one.");

	user_pb.add_contact(ret);
}

void	ContactMaker::list_contacts()
{
	Contact curr;
	Contact *to_print;

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


	for(int i = 0; i < user_pb.existing_contacts; i++)
	{
		curr = to_print[i];
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

void ContactMaker::search()
{
	Contact to_print;
	string input;

	list_contacts();
	cout << "\nWhat entry do you want to look at?" << std::endl;
	std::getline(std::cin, input);
	trim(input);

	while(!fully_numeric(input))
	{
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