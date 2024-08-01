#include "../headers/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(string const target) : AForm("RobotomyRequestForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src){}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::action() const
{
	std::cout << CYAN "Drilling noises" RESET << std::endl;
	if (rand() % 2)
		std::cout << GREEN <<  this->getTarget() << " has been robotomized successfully" RESET << std::endl;
	else
		std::cout << RED << this->getTarget() << " robotomization failed" RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */