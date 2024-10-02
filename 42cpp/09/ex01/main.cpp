#include "headers/general.hpp"
#include "headers/RPN.hpp"

void incorrect_usage()
{
	cout << RED << "Usage: ./RPN (Polish Math Expression)\n\tEG:  " BOLD CYAN "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << RESET << endl;
	exit(1);
}

int main(int ac, char **av)
{
	if(ac != 2)
		incorrect_usage();
	string input = string(av[1]);

	try
	{
		cout << RPN::evaluate(input);
	}
	catch(std::exception &e)
	{
		std::cerr << RED "Error: " CYAN << e.what() << RESET << endl;
		return 1;
	}
}