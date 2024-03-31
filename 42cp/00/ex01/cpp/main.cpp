#include "../headers/ContactMaker.h"
#include "../headers/utils.h"

bool valid_input(string s)
{
	string valid[] = {"1", "2", "3", "ADD", "SEARCH", "EXIT"};

	for(int i = 0; i < 6; i++)
		if(s == valid[i])
			return true;
	return false;
}

int main()
{
	string input = "";
	ContactMaker helper;

	while(1)
	{	
		print_stuff(OPTIONS);
		std::getline(std::cin, input);
		tidy(input);
		while(!valid_input(input))
		{
			print_stuff(OPT_ERROR);
			std::getline(std::cin, input);
			tidy(input);
		}

		if(input == "1" || input == "ADD")
			helper.make_contact();
		else if(input == "2" || input == "SEARCH")
			helper.search();
		else
			break;
	}
	print_end();
}