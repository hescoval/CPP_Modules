#include "headers/general.hpp"
#include "headers/PMergeMe.hpp"

void incorrect_usage()
{
	cout << RED << "Usage: ./PMergeMe (Sequence of Numbers)\n\tEG:  " BOLD CYAN "./PMergeMe 213 21 203 219 321" << RESET << endl;
	exit(1);
}

void input_treatment(string &input)
{
	trim(input);
	replace_whitespace(input);
	if(input.find_first_not_of("0123456789 ") != string::npos)
		throw std::runtime_error("Invalid character found in input");

	remove_consecutives(input, ' ');
}

int main(int ac, char **av)
{
	if(ac < 2)
		incorrect_usage();

	string input;

	for(int i = 1; i < ac; i++)
		input += " " + string(av[i]);

	try
	{
		input_treatment(input);
		PMergeMe inputSorter;
		inputSorter.Sort(input);
	}
	catch(std::exception &e)
	{
		std::cerr << RED "Error: " CYAN << e.what() << RESET << endl;
		return 1;
	}
}