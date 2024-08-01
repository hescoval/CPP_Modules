#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "general.hpp"
# include "Form.hpp"

class Bureaucrat
{
	private:
		string const	_name;
		int				_grade;

	public:

		Bureaucrat(string const name = "Default Bureaucrat", int grade = 150);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();


		void			signForm(Form &form);

		string const &	getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

		Bureaucrat &	operator=( Bureaucrat const & rhs );

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
};

std::ostream &				operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */