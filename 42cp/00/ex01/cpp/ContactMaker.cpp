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

}