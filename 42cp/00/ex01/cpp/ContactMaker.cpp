#include "../headers/ContactMaker.h"
#include "../headers/utils.h"

string ContactMaker::get_input(string field)
{
	print_stuff(HEADER);
	string input = "";

	cout << "Enter the Contact's " << field << std::endl;
	std::getline(std::cin, input);
	trim(input);

	while(empty_string(input))
	{
		print_stuff(HEADER);
		if(field == "Darkest Secret")
			cout << "Come on, everyone has one." << std::endl;
		else
			cout << "No contact field can be empty." << std::endl;
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
	ret.darkest_secret = get_input("Darkest Secret");

	user_pb.add_contact(ret);
}

void ContactMaker::search()
{
	Contact to_print;
	string input;

	try
	{
		user_pb.list_and_find_contact();
	}
	catch(const std::exception& e)
	{
		cout << e.what() << std::endl;
		sleep(3);
		return;
	}

	cout << "\nWhat entry do you want to look at?" << std::endl;
	std::getline(std::cin, input);
	trim(input);

	while(!fully_numeric(input))
	{
		user_pb.list_and_find_contact();
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