#include "../headers/general.hpp"

void trim(std::string &test)
{
	size_t end = test.size() - 1;

	while(end > 0 && isspace(test[end]))
		end--;
	
	test.erase(end + 1);

	size_t i = 0;

	while(i < test.size() && isspace(test[i]))
		i++;
	
	test.erase(0, i);
}
