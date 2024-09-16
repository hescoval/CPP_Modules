#include "headers/general.hpp"
#include "headers/easyfind.hpp"
#include <vector>

static void enter_to_continue()
{
	cout << CYAN << "\n\nPress |ENTER| TWICE to continue" << RESET << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("clear");
}

static void int_number_not_found()
{
    cout << CYAN "Filling a std::vector with the number from " << GREEN "0" << CYAN " -> " << GREEN "9"  RESET << endl;
    std::vector<int> vec;
    int to_find = 12;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try
    {
        cout << CYAN "Trying to find the number" << GREEN " [" << to_find << "]" << CYAN" in the vector" RESET << endl;
        std::vector<int>::iterator it = easyfind(vec, to_find);
        cout << GREEN "Found: " << *it << RESET << endl;
    }
    catch (std::exception &e)
    {
        cout << RED "Not found" RESET << endl;
    }
}

static void int_number_found()
{  
    cout << CYAN "Filling a std::vector with the number from " << GREEN "0" << CYAN " -> " << GREEN "9"  RESET << endl;
    std::vector<int> vec;
    int to_find = 7;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try
    {
        cout << CYAN "Trying to find the number" << GREEN " [" << to_find << "]" << CYAN" in the vector" RESET << endl;
        std::vector<int>::iterator it = easyfind(vec, to_find);
        cout << GREEN "Found: " << *it << RESET << endl;
    }
    catch (std::exception &e)
    {
        cout << RED "Not found" RESET << endl;
    }
}

int main()
{
    int_number_found();
    enter_to_continue();
    int_number_not_found();
}