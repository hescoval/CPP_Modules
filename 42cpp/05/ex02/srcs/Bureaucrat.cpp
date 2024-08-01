#include "../headers/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(string const name, int grade) : 
		_name(name),
		_grade(grade)
{
	cout << YELLOW << "Bureaucrat \"" <<  name << "\" trying to get certified " "(grade = " << grade << ")" RESET << endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	cout << GREEN << "Bureaucrat \"" <<  name << "\" got certified " RESET << endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) :	
		_name(src.getName()),
		_grade(src.getGrade())
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this == &rhs )
		return *this;

	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	// Want : <name>, bureaucrat grade <grade>
	o << GREEN << i.getName() << RESET ", bureaucrat grade " YELLOW << i.getGrade() << RESET << endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "This Bureaucrat's Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "This Bureaucrat's Grade is too low";
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		cout << YELLOW "\n" << this->getName() << GREEN " signs " YELLOW << form.getName() << RESET << endl;
	}
	catch(const std::exception& e)
	{
		cout << YELLOW "\n" << this->getName() << RED " cannot sign " YELLOW  << form.getName() << RED " because his grade wasn't high enough." << RESET << endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		cout << YELLOW "\n" << this->getName() << GREEN " executes " YELLOW << form.getName() << RESET << endl;
	}
	catch(const std::exception& e)
	{
		cout << YELLOW "\n" << this->getName() << RED " cannot execute " YELLOW << form.getName() << RED " because his grade wasn't high enough." << RESET << endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

string const & Bureaucrat::getName() const
{
	return this->_name;
}

/* ************************************************************************** */