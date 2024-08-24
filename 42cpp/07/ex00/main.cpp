#include "headers/general.hpp"
#include "headers/template.hpp"

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void test_with_doubles()
{
    cout << GREEN "-Testing with doubles-\n" RESET << endl;
    double x = 32134014040114040140140142.3;
    double y = 2.2;

    cout << GREEN "x = " CYAN << x << endl;
    cout << GREEN "y = " CYAN << y << "\n" << endl;

    cout << YELLOW "-Swapping values-\n" RESET << endl;
    ::swap(x, y);

    cout << GREEN "x = " CYAN << x << endl;
    cout << GREEN "y = " CYAN << y << "\n" << endl;
    enter_to_continue();

    cout << YELLOW "-Testing min function-\n" RESET << endl;
    cout << GREEN "Min between x ( " << x << " ) and y ( " << y << " ) is: " << ::min(x, y) << "\n" << endl;;
    enter_to_continue();

    cout << YELLOW "-Testing max function-\n" RESET << endl;
    cout << GREEN "Max between x ( " << x << " ) and y ( " << y << " ) is: " << ::max(x, y) << "\n" << endl;;

    enter_to_continue();
}

static void test_with_strings()
{
    cout << GREEN "-Testing with strings-\n" RESET << endl;
    string x = "A small string";
    string y = "Slightly sigger string";

    cout << GREEN "x = " CYAN << x << endl;
    cout << GREEN "y = " CYAN << y << "\n" << endl;

    cout << YELLOW "-Swapping values-\n" RESET << endl;
    ::swap(x, y);

    cout << GREEN "x = " CYAN << x << endl;
    cout << GREEN "y = " CYAN << y << "\n" << endl;
    enter_to_continue();

    cout << YELLOW "-Testing min function-\n" RESET << endl;
    cout << GREEN "Min between x ( " << x << " ) and y ( " << y << " ) is: " << ::min(x, y) << "\n" << endl;;
    enter_to_continue();

    cout << YELLOW "-Testing max function-\n" RESET << endl;
    cout << GREEN "Max between x ( " << x << " ) and y ( " << y << " ) is: " << ::max(x, y) << "\n" << endl;;

    enter_to_continue();
}

static void test_with_int()
{
    cout << GREEN "-Testing with integers-\n" RESET << endl;
    int x = 15;
    int y = 70;

    cout << GREEN "x = " CYAN << x << endl;
    cout << GREEN "y = " CYAN << y << "\n" << endl;

    cout << YELLOW "-Swapping values-\n" RESET << endl;
    ::swap(x, y);

    cout << GREEN "Int x = " CYAN << x << endl;
    cout << GREEN "Int y = " CYAN << y << "\n" << endl;
    enter_to_continue();

    cout << YELLOW "-Testing min function-\n" RESET << endl;
    cout << GREEN "Min between x ( " << x << " ) and y ( " << y << " ) is: " << ::min(x, y) << "\n" << endl;;
    enter_to_continue();

    cout << YELLOW "-Testing max function-\n" RESET << endl;
    cout << GREEN "Max between x ( " << x << " ) and y ( " << y << " ) is: " << ::max(x, y) << "\n" << endl;;
    enter_to_continue();
}

int main()
{
    test_with_int();
    test_with_strings();
    test_with_doubles();
}