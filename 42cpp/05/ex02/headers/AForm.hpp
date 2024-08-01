#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "general.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		string const	_name;
		bool			_signed;
		int				_gradeToSign;
		int				_gradeToExecute;
		string const	_target;
		
	public:

		AForm(string const name = "Default AForm", bool isSigned = false, int gradeToSign = 150, int gradeToExecute = 150, string const target = "Default");
		AForm( AForm const & src );
		virtual ~AForm();

		string const &	getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		string const &	getTarget() const;
		void			beSigned(Bureaucrat &bureaucrat);

		void			execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


		AForm &		operator=( AForm const & rhs );
};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */