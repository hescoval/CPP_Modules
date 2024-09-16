#include "headers/general.hpp"
#include "headers/Span.hpp"

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

int main()
{
	enter_to_continue();

	return 0;
}