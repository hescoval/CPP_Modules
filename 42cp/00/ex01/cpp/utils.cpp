#include "../headers/general.h"

string i_to_s(int num)
{
	string fill = "";
	string ret = "";
	char next;

	if(num == 0)
		return fill += '0';
	
	if(num < 0)
	{
		fill += '-';
		num *= -1;
	}

	while(num)
	{
		next = (num % 10) + 48;
		fill += next;
		num /= 10;
	}

	for(int i = fill.length(); i >= 0; i--)
		ret += fill[i];

	return ret;
}

void make_uppercase(string &test)
{
	for(int i = 0; i < test.size(); i++)
		test[i] = toupper(test[i]);
}

void trim(string &test)
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

// Printing

void print_options()
{
	cout << "1. Add\n\n2. Search\n\n3. Exit" << std::endl;
}

void print_header()
{
	
}

void print_stuff(options option)
{
	print_header();
}