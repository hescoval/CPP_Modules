#include "../headers/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(string const target) : AForm("PresidentialPardonForm", false, 25, 5, target) {} 

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src){}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::action() const
{
	std::cout << YELLOW "\n" << this->getTarget() << GREEN " has been pardoned by Zafod Beeblebrox" RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */