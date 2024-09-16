#include "headers/general.hpp"
#include "headers/Span.hpp"

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void subjectTest()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void addNumber_exception()
{
	Span sp = Span(1);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void bigSize()
{
	int size = 10000;
	Span sp = Span(size);
	for (int i = 0; i < size; i++)
	{
		std::cout << CYAN "Adding number " GREEN << i << RESET << std::endl;
		sp.addNumber(i);
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void rangeAdd()
{
	Span sp = Span(10);
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i * 1239103219);
	try
	{
		sp.addRange(v.begin(), v.end());
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void invalid_Iterators()
{
	Span sp = Span(10);
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		sp.addRange(v.end(), v.begin());
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void custom_constructors()
{
	Span sp = Span(10);
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		sp.addRange(v.begin(), v.end());
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Span sp2 = Span(sp);
	Span sp3 = sp;

	std::cout << CYAN << "Original Span: " GREEN << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << CYAN << "\nCopy Span: " GREEN << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << RESET << std::endl;

	std::cout << CYAN "\nAssignment Span: " GREEN << std::endl;
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << RESET << std::endl;
}

int main()
{
    subjectTest();
	enter_to_continue();
	addNumber_exception();
	enter_to_continue();
	bigSize();
	enter_to_continue();
	rangeAdd();
	enter_to_continue();
	invalid_Iterators();
	enter_to_continue();
	custom_constructors();

	return 0;
}