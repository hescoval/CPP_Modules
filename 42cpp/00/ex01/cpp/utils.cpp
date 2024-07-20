#include "../headers/general.h"
#include "../headers/Contact.h"

bool fully_numeric(string s)
{
	long unsigned int size = s.length();

	if(size == 0)
		return false;
		
	for(long unsigned int i = 0; i < size; i++)
	{
		if(!isdigit(s[i]))
			return false;
	}
	return true;
}

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

	for(int i = fill.length() - 1; i >= 0; i--)
		ret += fill[i];

	return ret;
}

bool empty_string(string s)
{
	for(long unsigned int i = 0; i < s.length(); i++)
	{
		if(!isspace(s[i]))
			return false;
	}
	return true;
}

void make_uppercase(string &test)
{
	for(long unsigned int i = 0; i < test.size(); i++)
		test[i] = toupper(test[i]);
}

void trim(string &test)
{
	int end = test.length() - 1;

	while(end > 0 && isspace(test[end]))
		end--;
	
	test.erase(end + 1);

	long unsigned int i = 0;

	while(i < test.length() && isspace(test[i]))
		i++;
	
	test.erase(0, i);
}

void tidy(string &s)
{
	trim(s);
	make_uppercase(s);
}