#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm(string const target = "Default");
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		void	action() const;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */