# include "headers/general.hpp"
# include "headers/Bureaucrat.hpp"


static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void check_valid_bureaucrats()
{
    Bureaucrat b1("B1", 1);
    Bureaucrat b2("B2", 150);
    Bureaucrat b3("B3", 75);
}

static void check_exceptions()
{
    try
    {
        Bureaucrat b1("B1", 0);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        cout << RED << e.what() << RESET << endl;
    }

    try
    {
        Bureaucrat b1("B2", 151);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        cout << RED << e.what() << RESET << endl;
    }
}  

static void inc_dec_check()
{
    Bureaucrat b1("Bad Bureaucrat", 150);
    Bureaucrat b2("Good Bureaucrat", 1);
    try
    {   
        cout << YELLOW "Trying to decrement grade 150 " RESET << endl;
        b1.decrementGrade();
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        cout << RED << e.what() << RESET << endl;
    }

    try
    {
        cout << YELLOW "Trying to increment grade 1 " RESET << endl;
        b2.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    
    cout << endl;
    cout << b1;
    cout << b2;
}

int main()
{
    check_valid_bureaucrats();
    enter_to_continue();
    check_exceptions();
    enter_to_continue();
    inc_dec_check();
    return 0;
}