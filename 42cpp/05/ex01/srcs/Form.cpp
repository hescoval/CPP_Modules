#include "../headers/Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(string const name, bool isSigned, int gradeToExecute, int gradeToSign) :
		 _name(name),
		 _signed(isSigned),
		 _gradeToExecute(gradeToExecute),
		 _gradeToSign(gradeToSign)
{
	cout << YELLOW << "Form \"" <<  name << "\" trying to get certified " "(gradeToSign = " << gradeToSign << ", gradeToExecute = " << gradeToExecute << ")" RESET << endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	cout << GREEN << "Form \"" <<  name << "\" got certified " RESET << endl;
}

Form::Form( const Form & src ) : 
	_name(src.getName()),
	_signed(src.getSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute())
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if(this == &rhs)
		return *this;
	_signed = rhs.getSigned();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << GREEN "Form \"" << i.getName() << "\":" RESET << endl;
	o << "\tGrade to Sign: " YELLOW << i.getGradeToSign() << RESET << endl;
	o << "\tGrade to Execute: " YELLOW << i.getGradeToExecute() << RESET << endl;
	o << "\tIs this form signed? " << (i.getSigned() ? " ✅ " : " ❌ ")  << endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return "This form's grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "This form's grade is too low";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string const &	Form::getName() const
{
	return _name;
}

bool		Form::getSigned() const
{
	return _signed;
}

int			Form::getGradeToSign() const
{
	return _gradeToSign;
}

int			Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

/* ************************************************************************** */