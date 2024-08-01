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
    Form F1("Form 1", false, 1, 1);
    Form F2("Form 2", false, 150, 150);

    cout << endl;
    cout << F1;
    cout << endl;
    cout << F2;
}

static void create_invalid_forms()
{
    try
    {
        Form F3("Form 3", false, 0, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        Form F4("Form 4", false, 1, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        Form F5("Form 5", false, 151, 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        Form F6("Form 6", false, 150, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
}

static void valid_sign_forms()
{
    Bureaucrat B1("Bureaucrat 1", 1);
    Bureaucrat B2("Bureaucrat 2", 150);

    Form F1("Form 1", false, 1, 1);
    Form F2("Form 2", false, 150, 150);

    cout << endl;
    cout << B1;
    cout << B2;
    cout << endl;
    cout << F1;
    cout << F2;

    cout << endl;
    cout << YELLOW << "Signing Form 1 with Bureaucrat 1" << RESET << endl;
    F1.beSigned(B1);

    cout << YELLOW << "Signing Form 2 with Bureaucrat 2" << RESET << endl;
    F2.beSigned(B2);

    cout << endl;
    cout << F1;
    cout << F2;
}

static void invalid_sign_forms()
{
    Bureaucrat B1("Bureaucrat 1", 1);
    Bureaucrat B2("Bureaucrat 2", 150);

    Form F1("Form 1", false, 1, 1);
    Form F2("Form 2", false, 149, 149);

    cout << endl;
    cout << B1;
    cout << B2;
    cout << F1;
    cout << F2;

    try
    {
        cout << YELLOW << "Trying to sign Form 1 with Bureaucrat 2" << RESET << endl;
        F1.beSigned(B2);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        cout << YELLOW << "Trying to sign Form 2 with Bureaucrat 2" << RESET << endl;
        F2.beSigned(B2);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    cout << endl;
    cout << F1;
    cout << F2;
}

static void sign_form_test()
{
    Bureaucrat B1("Bureaucrat 1", 1);
    Bureaucrat B2("Bureaucrat 2", 150);

    Form F1("Form 1", false, 1, 1);
    Form F2("Form 2", false, 149, 149);

    cout << endl;
    cout << F1;
    cout << F2;

    cout << endl;
    cout << YELLOW << "Signing Form 1 with Bureaucrat 1" << RESET << endl;
    B1.signForm(F1);
    cout << endl;

    cout << YELLOW << "Signing Form 2 with Bureaucrat 2" << RESET << endl;
    B2.signForm(F2);

    cout << endl;
    cout << F1;
    cout << F2;
}

int main()
{
    create_valid_forms();
    enter_to_continue();
    create_invalid_forms();
    enter_to_continue();
    valid_sign_forms();
    enter_to_continue();
    invalid_sign_forms();
    enter_to_continue();
    sign_form_test();

    return 0;
}