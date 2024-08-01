#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm(string const target = "Default");
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		void	action() const;
};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */