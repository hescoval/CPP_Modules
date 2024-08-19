#include "../headers/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(string const target) : AForm("ShrubberyCreationForm", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::action() const
{
	string filename = this->getTarget() + "_shrubbery";
	std::ifstream input;
	std::ofstream target;

	input.open("ascii_trees.txt");
	target.open(filename.c_str());
	if (!input.is_open() || !target.is_open())
	{
		input.close();
		target.close();
		std::cerr << RED "\nError: could not open file\n" RESET << std::endl;
		return ;
	}

	target << input.rdbuf();
	input.close();
	target.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */