# include "headers/general.hpp"
# include "headers/Bureaucrat.hpp"
# include "headers/AForm.hpp"
# include "headers/PresidentialPardonForm.hpp"
# include "headers/RobotomyRequestForm.hpp"
# include "headers/ShrubberyCreationForm.hpp"
# include "headers/Intern.hpp"
# include <ctime>

static void internTest()
{
    Intern intern;
    AForm* form;

    form = intern.makeForm("shrubbery creation", "home");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("robotomy request", "somebody");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("presidential pardon", "Una Bomber");
    std::cout << *form << std::endl;
    delete form;

    try
    {
        form = intern.makeForm("nonexistent form", "random");
        std::cout << *form << std::endl;
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
}

int main()
{
    system("clear");
    internTest();
}