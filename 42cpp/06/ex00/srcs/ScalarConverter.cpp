#include "../headers/ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool	ScalarConverter::check_Char(string str)
{
	if(str.length() != 1 || isdigit(str[0]))
		return false;

	printChar(str[0], str);
	printInt(static_cast<int>(str[0]), str);
	printFloat(static_cast<float>(str[0]), str);
	printDouble(static_cast<double>(str[0]), str);

	return true;
}

bool	ScalarConverter::check_Int(string str)
{
	bool dot = str.find('.') != string::npos;
	bool f = str.find('f') != string::npos;
	size_t minus_sign = str.find_last_of('-');
	size_t plus_sign = str.find_last_of('+');

	if(	(minus_sign != string::npos && plus_sign != string::npos) ||
		(minus_sign != string::npos && minus_sign != 0)			 || 
		(plus_sign != string::npos && plus_sign != 0))
		return false;

	if(dot || f)
		return false;

	for(size_t i = 0; i < str.size(); i++)
	{
		if(i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if(!isdigit(str[i]))
			return false;
	}

	int num_representation = atoi(str.c_str());

	printChar(static_cast<char>(num_representation), str);
	printInt(num_representation, str);
	printFloat(static_cast<float>(num_representation), str);
	printDouble(static_cast<double>(num_representation), str);

	return true;
}

bool	ScalarConverter::check_Float(string str)
{
	(void)str;
	return false;
}

bool	ScalarConverter::check_Double(string str)
{
	(void)str;
	return false;
}

void	ScalarConverter::printChar(char c, string str)
{
	long double num = strtold(str.c_str(), NULL);
	cout << GREEN << std::numeric_limits<char>::min() << RESET << endl;

	if(num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		cout << "char: Over/Under Flow" << endl;

	else if(isprint(c))
		cout << "char: '" << c << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
}

void	ScalarConverter::printInt(int num, string str)
{
	long double large = strtold(str.c_str(), NULL);

	if(large > std::numeric_limits<int>::max() || large < std::numeric_limits<int>::min())
		cout << "int: Over/Under Flow" << endl;
	else
		cout << "int: " << num << endl;
}

void	ScalarConverter::printFloat(float num, string str)
{
	(void)num;
	(void)str;
}

void	ScalarConverter::printDouble(double num, string str)
{
	(void)num;
	(void)str;
}

bool	ScalarConverter::check_pseudo(string str)
{
	string s(str);

	if(s == "nan")
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: nanf" << endl;
		cout << "double: nan" << endl;
		return true;
	}

	if( s == "-inf" || s == "+inf" || s == "+inff" || s == "-inff")
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << s[0] << "inff" << endl;
		cout << "double: " << s[0] << "inf" << endl;
		return true;
	}

	return false;
}

void 	ScalarConverter::convert(string str)
{
	if(check_pseudo(str))
		return ;
	if(check_Char(str))
		return;
	if(check_Int(str))
		return;
	if(check_Float(str))
		return;
	if(check_Double(str))
		return;
	
	cout << "char: Nonsense" << endl;
	cout << "int: Nonsense" << endl;
	cout << "float: Nonsense" << endl;
	cout << "double: Nonsense" << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */