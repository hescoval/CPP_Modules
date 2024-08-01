#include "../headers/Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	possibleForms[0] = "shrubbery creation";
	possibleForms[1] = "robotomy request";
	possibleForms[2] = "presidential pardon";

	_functions[0] = &Intern::createShrubberyCreationForm;
	_functions[1] = &Intern::createRobotomyRequestForm;
	_functions[2] = &Intern::createPresidentialPardonForm;
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* Intern::createShrubberyCreationForm(string const target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(string const target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(string const target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(string const formName, string const target)
{
	for(int i = 0; i < 3; i++)
		if(formName == possibleForms[i])
			return (this->*_functions[i])(target);

	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "The internt can't file that form.";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */