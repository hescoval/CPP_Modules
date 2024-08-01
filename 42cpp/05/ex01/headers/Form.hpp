#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "general.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		string const	_name;
		bool			_signed;
		int				_gradeToSign;
		int				_gradeToExecute;
	public:

		Form(string const name = "Default Form", bool isSigned = false, int gradeToSign = 150, int gradeToExecute = 150);
		Form( Form const & src );
		~Form();

		string const &	getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Form &		operator=( Form const & rhs );
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */