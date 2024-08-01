# include "headers/general.hpp"
# include "headers/Bureaucrat.hpp"
# include "headers/AForm.hpp"
# include "headers/PresidentialPardonForm.hpp"
# include "headers/RobotomyRequestForm.hpp"
# include "headers/ShrubberyCreationForm.hpp"
# include <ctime>

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void ShrubberyTest()
{
    Bureaucrat B1("B1", 1);
    Bureaucrat B2("B2", 150);

    ShrubberyCreationForm F1("F1");
    ShrubberyCreationForm F2("F2");

    B1.signForm(F1);
    B2.signForm(F2);

    B1.executeForm(F1);
    B2.executeForm(F2);
}

static void PardonTest()
{
    Bureaucrat B1("B1", 1);
    Bureaucrat B2("B2", 150);

    PresidentialPardonForm F1("F1");
    PresidentialPardonForm F2("F2");

    B1.signForm(F1);
    B2.signForm(F2);

    B1.executeForm(F1);
    B2.executeForm(F2);
}

static void RobotDrillingTest()
{
    Bureaucrat B1("B1", 1);
    Bureaucrat B2("B2", 150);

    RobotomyRequestForm F1("F1");
    RobotomyRequestForm F2("F2");

    B1.signForm(F1);
    B2.signForm(F2);

    B1.executeForm(F1);
    B2.executeForm(F2);
}

static void RobotDrillRNGTest()
{
    Bureaucrat B1("B1", 1);

    RobotomyRequestForm F1("Randomness Check");

    B1.signForm(F1);

    std::srand(std::time(0));
    for(int i = 0; i < 5 ; i++)
        B1.executeForm(F1);
}

int main()
{
    ShrubberyTest();
    enter_to_continue();
    PardonTest();
    enter_to_continue();
    RobotDrillingTest();
    enter_to_continue();
    RobotDrillRNGTest();
}