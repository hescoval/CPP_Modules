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
	cout << YELLOW "Testing with a normal integer array\n" RESET << endl;
    int array[5] = {2, 4 , 6 , 8, 10};

    ::iter(array, 5, ::print);

	enter_to_continue();
}

static void string_test()
{
	cout << YELLOW "Testing with a string array\n" RESET << endl;
	string array[5] = {"Hello", "World", "This", "Is", "A Test"};

	::iter(array, 5, ::print);

	enter_to_continue();
}

static void const_array_test()
{
	cout << YELLOW "Testing with same arrays, but CONST\n" RESET << endl;
	const int array[5] = {2, 4 , 6 , 8, 10};
	const string array2[5] = {"Hello", "World", "This", "Is", "A Test"};

	::iter(array, 5, ::print);
	cout << "\n" << endl;
	::iter(array2, 5, ::print);

	enter_to_continue();
}

int main()
{
    int_test();
	string_test();
	const_array_test();
}