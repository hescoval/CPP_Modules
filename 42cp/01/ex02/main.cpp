#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;

int main()
{
	string	variable("HI THIS IS BRAIN");
	string*	stringPTR = &variable;
	string&	stringREF = variable;

	cout << &variable << std::endl;
	cout << stringPTR << std::endl;
	cout << &stringREF << std::endl;

	cout << variable << std::endl;
	cout << stringPTR << std::endl;
	cout << stringREF << std::endl;
}