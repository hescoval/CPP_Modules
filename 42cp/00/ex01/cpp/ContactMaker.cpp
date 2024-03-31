#include "../headers/ContactMaker.h"
#include "../headers/utils.h"

string ContactMaker::get_input(string field)
{

}

void ContactMaker::make_contact()
{
	Contact ret;

	ret.first_name = get_input("First Name");
	ret.first_name = get_input("Last Name");
	ret.first_name = get_input("Nick Name");
	ret.first_name = get_input("Phone Number");
	ret.first_name = get_input("Darkest Secret");

	user_pb.add_contact(ret);
}

void ContactMaker::search()
{
	Contact to_print;

	try
	{
		to_print = user_pb.list_and_find_contact();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	print_contact(to_print);
}