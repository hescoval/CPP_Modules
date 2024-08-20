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

	if(dot || f)
		return false;

	int num_representation = atoi(str.c_str());
	printChar(static_cast<char>(num_representation), str);
	printInt(num_representation, str);
	printFloat(static_cast<float>(num_representation), str);
	printDouble(static_cast<double>(num_representation), str);

	return true;
}

bool	ScalarConverter::check_Float(string str)
{
	bool f_loc = str.find_last_of("f") != std::string::npos;
	bool dot_loc = str.find_last_of(".") != std::string::npos;

	if(!f_loc && !dot_loc)
		return false;

	float num_representation = strtof(str.c_str(), NULL);

	printChar(static_cast<char>(num_representation), str);
	printInt(static_cast<int>(num_representation), str);
	printFloat(num_representation, str);
	printDouble(static_cast<double>(num_representation), str);

	return true;
}

bool	ScalarConverter::check_Double(string str)
{
	bool dot_loc = str.find_last_of(".") != std::string::npos;

	if(!dot_loc)
		return false;

	double num_representation = strtod(str.c_str(), NULL);
	cout << CYAN << num_representation << RESET << endl;

	printChar(static_cast<char>(num_representation), str);
	printInt(static_cast<int>(num_representation), str);
	printFloat(static_cast<float>(num_representation), str);
	printDouble(num_representation, str);

	return true;
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
	long double large = strtold(str.c_str(), NULL);

	if(large > std::numeric_limits<float>::max() || large < -std::numeric_limits<float>::max())
		cout << "float: Over/Under Flow" << endl;
	else
		cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << endl;
}

void	ScalarConverter::printDouble(double num, string str)
{
	long double large = strtold(str.c_str(), NULL);

	if(large > std::numeric_limits<double>::max() || large < -std::numeric_limits<double>::max())
		cout << "double: Over/Under Flow" << endl;
	else
		cout << "double: " << num << endl;
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

bool	ScalarConverter::check_gibberish(string str)
{
	string valid_chars("0123456789.f-+");
	string digits("0123456789");
	size_t f_loc = str.find_last_of("f");
	size_t dot_loc = str.find_last_of(".");
	size_t minus_sign = str.find_last_of('-');
	size_t plus_sign = str.find_last_of('+');

	if(	(minus_sign != string::npos && plus_sign != string::npos) ||
		(minus_sign != string::npos && minus_sign != 0)			 || 
		(plus_sign != string::npos && plus_sign != 0))
		return true;

	if(str.find_first_of(digits) == std::string::npos)
		return true;

	for(size_t i = 0; i < str.size(); i++)
		if(valid_chars.find_first_of(str[i]) == std::string::npos)
			return true;

	if(f_loc != std::string::npos && (str.find_first_of("f") != f_loc || f_loc != str.size() - 1 ))
		return true;

	if(dot_loc != std::string::npos && (str.find_first_of(".") != dot_loc || dot_loc > f_loc))
		return true;

	if(f_loc != std::string::npos && dot_loc == std::string::npos)
		return true;

	return false;
}

void 	ScalarConverter::convert(string str)
{
	if(check_pseudo(str))
		return ;
	if(check_gibberish(str))
	{
		cout << "char: Nonsense" << endl;
		cout << "int: Nonsense" << endl;
		cout << "float: Nonsense" << endl;
		cout << "double: Nonsense" << endl;
		return;
	}
	if(check_Char(str))
		return;
	if(check_Int(str))
		return;
	if(check_Float(str))
		return;
	if(check_Double(str))
		return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */