#include "headers/general.hpp"
#include "headers/template.hpp"

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void int_test()
{
    int array[5] = {2, 4 , 6 , 8, 10};

    ::iter(array, 5, ::print);
	
	::iter((const int*)array, 5, ::print);
	enter_to_continue();
}

int main()
{
    int_test();
}