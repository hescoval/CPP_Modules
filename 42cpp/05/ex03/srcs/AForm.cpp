#include "../headers/AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(string const name, bool isSigned, int gradeToExecute, int gradeToSign, string const target) :
		 _name(name),
		 _signed(isSigned),
		 _gradeToSign(gradeToSign),
		 _gradeToExecute(gradeToExecute),
		 _target(target)
{
	cout << YELLOW << "Trying to pass the Form \"" <<  name << "\" " "(gradeToSign = " << gradeToSign << ", gradeToExecute = " << gradeToExecute << ", Target = " << target << ")" RESET << endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	cout << GREEN << "Form \"" <<  name << "\" has passed " RESET << endl;
}

AForm::AForm( const AForm & src ) : 
	_name(src.getName()),
	_signed(src.getSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute())
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if(this == &rhs)
		return *this;
	_signed = rhs.getSigned();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << GREEN "Form \"" << i.getName() << "\":" RESET << endl;
	o << "\tGrade to Sign: " YELLOW << i.getGradeToSign() << RESET << endl;
	o << "\tGrade to Execute: " YELLOW << i.getGradeToExecute() << RESET << endl;
	o << "\tIs this Form signed? " << (i.getSigned() ? " ✅ " : " ❌ ")  << endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	if (_signed == false)
		throw AForm::FormNotSignedException();
	this->action();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "This Form is not signed, so it can't be executed";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "One of this AForm's grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "One of this AForm's grade is too low";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string const &	AForm::getName() const
{
	return _name;
}

bool		AForm::getSigned() const
{
	return _signed;
}

int			AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int			AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

string const & AForm::getTarget() const
{
	return _target;
}

/* ************************************************************************** */