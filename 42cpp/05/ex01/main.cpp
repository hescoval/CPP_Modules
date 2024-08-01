# include "headers/general.hpp"
# include "headers/Bureaucrat.hpp"
# include "headers/Form.hpp"


static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void create_valid_forms()
{
    Bureaucrat B1("Bureaucrat 1", 1);
    Bureaucrat B2("Bureaucrat 2", 150);
    Form F1("Form 1", false, 1, 1);
    Form F2("Form 2", false, 150, 150);
}

int main()
{
    create_valid_forms();
    return 0;
}