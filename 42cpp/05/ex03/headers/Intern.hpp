#ifndef INTERN_HPP
# define INTERN_HPP

#include "general.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:

			Intern();
			Intern( Intern const & src );
			~Intern();

			AForm*	makeForm(string const formName, string const target);

			Intern &		operator=( Intern const & rhs );

			class FormNotFoundException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
	private:
			string 	possibleForms[3];
			AForm*	(Intern::*_functions[3])(string const target);	
			AForm*	createShrubberyCreationForm(string const target);
			AForm*	createRobotomyRequestForm(string const target);
			AForm*	createPresidentialPardonForm(string const target);
};

#endif /* ********************************************************** INTERN_H */