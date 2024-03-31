#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

void make_uppercase(std::string &test)
{
	for(int i = 0; i < test.size(); i++)
		test[i] = toupper(test[i]);
}

void trim(std::string &test)
{
	int end = test.size() - 1;

	while(end > 0 && isspace(test[end]))
		end--;
	
	test.erase(end + 1);

	int i = 0;

	while(i < test.size() && isspace(test[i]))
		i++;
	
	test.erase(0, i);
}

int main(int ac, char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		exit(0);
	}

	for(int i = 1; i < ac; i++)
	{
		std::string print(av[i]);

		trim(print);
		make_uppercase(print);

		std::cout << print;

		if(i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}