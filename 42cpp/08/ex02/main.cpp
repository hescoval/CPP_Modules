#include "headers/general.hpp"
#include "headers/MutantStack.hpp"
#include <list>


static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

void subject_tests()
{
	cout << BOLD GREEN "Subject tests" RESET << endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		cout << GREEN "Top: " BOLD CYAN << mstack.top() << RESET << endl;
		mstack.pop();
		cout << GREEN "Size: " BOLD CYAN << mstack.size() << RESET << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		for(int value = 1; it != ite; it++, value++)
		{
			cout << GREEN "Value " << value << ": " BOLD CYAN << *it << RESET << endl;
		}
		std::stack<int> s(mstack);
	}
}

void other_tests()
{
	std::list<int> lst;
	int to_push[] = {5, 17, 3, 5, 737, 0};
	int pushes = 0;
	
	while(pushes < 2)
		lst.push_back(to_push[pushes++]); // Not LIFO, but subject wants to use push_back() instead of push_front()

	cout << GREEN "Top: " BOLD CYAN << lst.back() << RESET << endl; 
	lst.pop_back();
	cout << GREEN "Size: " BOLD CYAN << lst.size() << RESET << endl;

	while(pushes < 6)
		lst.push_back(to_push[pushes++]);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	for(int value = 1; it != ite; it++, value++)
		cout << GREEN "Value " << value << ": " BOLD CYAN << *it << RESET << endl;
}

int main()
{

	subject_tests();
	enter_to_continue();
	other_tests();

	return 0;
}