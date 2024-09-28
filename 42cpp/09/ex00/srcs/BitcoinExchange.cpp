#include "../headers/BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(string crypto_file, string user_file, char delim, char crypto_delim)
{
	set_values(user_holdings, user_file, delim);
	set_values(crypto_values, crypto_file, crypto_delim);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ){(void)src;}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if(this == &rhs)
	{
		return *this;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::find_date_match(string date, double user_amount, double& value_at_date)
{
	std::multimap<string, double>::iterator crypto_it = crypto_values.begin();
	bool match = false;

	while(crypto_it->first <= date && crypto_it != crypto_values.end())
	{
		match = true;
		value_at_date = crypto_it->second * user_amount;
		crypto_it++;
	}

	if (!match)
		value_at_date = DATE_MATCH_NOT_FOUND;
}

void	BitcoinExchange::check_holdings()
{	
	std::multimap<string, double>::iterator user_it = user_holdings.begin();
	double value_at_date = 0;

	for(; user_it != user_holdings.end(); user_it++)
	{
		find_date_match(user_it->first, user_it->second, value_at_date);
		if(value_at_date == DATE_MATCH_NOT_FOUND)
			std::cerr << BOLD RED "Error, Skipping the [" BOLD CYAN "key, value" BOLD RED "] pair: [" BOLD CYAN << user_it->first << ", " << user_it->second << BOLD RED "] (Reason: " << BOLD CYAN "No earlier/matching date found in the data.csv file)\n" RESET;
		else
			std::cout << "At " GREEN << user_it->first << RESET " user had " CYAN << user_it->second << RESET " BTC valued at a total of " BOLD CYAN
			<< value_at_date << RESET << std::endl;
	}
}

std::tm BitcoinExchange::string_to_date(const std::string& dateStr) 
{
    std::tm tm = {};
    char* ptr = strptime(dateStr.c_str(), "%Y-%m-%d", &tm);
    if (!ptr) 
        throw std::runtime_error("Invalid date format");
    return tm;
}

bool BitcoinExchange::is_leap_year(int year) 
{
    return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

void	BitcoinExchange::check_date_format(std::tm date)
{
    if (date.tm_year < 0)
        throw std::runtime_error("Year must be non-negative");
    if (date.tm_mon < 0 || date.tm_mon > 11)
        throw std::runtime_error("Month must be between 1 and 12");
    if (date.tm_mday < 1)
        throw std::runtime_error("Day must be greater than 0");

    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int days = daysInMonth[date.tm_mon];
    if (date.tm_mon == 1 && is_leap_year(date.tm_year + 1900))
        days = 29;

    if (date.tm_mday > days)
        throw std::runtime_error("Day must be valid for the given month");
}

void BitcoinExchange::validate_date(string date_string)
{
	std::tm date = {};
	date = string_to_date(date_string);
	check_date_format(date);
}

void BitcoinExchange::check_gibberish(string str)
{
	string valid_chars("0123456789.+");
	string digits("0123456789");
	size_t dot_loc = str.find_last_of(".");
	size_t plus_sign = str.find_last_of('+');

	if((plus_sign != string::npos && plus_sign != 0))
		throw std::runtime_error("Invalid plus signs");

	if(str.find_first_of(digits) == std::string::npos)
		throw std::runtime_error("No digits found");

	for(size_t i = 0; i < str.size(); i++)
		if(valid_chars.find_first_of(str[i]) == std::string::npos)
			throw std::runtime_error("Invalid characters found");

	if(dot_loc != std::string::npos && (str.find_first_of(".") != dot_loc))
		throw std::runtime_error("Invalid dot location");
}

void BitcoinExchange::line_key_value_validations(string key, string value_string)
{
	validate_date(key);
	check_gibberish(value_string);
}

void BitcoinExchange::set_values(std::multimap<string, double>& map, string file_name, char delim)
{
	FileManager file_manager;
	string buffer, key, value_string;
	double value;

	try
	{
		file_manager.read_from(file_name);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}

	for(size_t line = 1; std::getline(file_manager.infile, buffer); line++)
	{
		trim(key = buffer.substr(0, buffer.find(delim)));
		trim(value_string = buffer.substr(buffer.find(delim) + 1));

		try
		{
			line_key_value_validations(key, value_string);
		}
		catch(std::exception &e)
		{
			std::cerr << BOLD RED "Error, Skipping line [" GREEN << line <<  BOLD RED "]:\n" BOLD CYAN << buffer << BOLD RED "\nReason: " BOLD CYAN << e.what() << RESET "\n\n\n";
			continue;
		}

		value = strtod(buffer.substr(buffer.find(delim) + 1).c_str(), NULL);
		if((value < 0 || value > 1000 ) && map == user_holdings)
		{
			std::cerr << BOLD RED "Error, Skipping line [" GREEN << line <<  BOLD RED "]:\n" BOLD CYAN << buffer << BOLD RED "\nReason: " BOLD CYAN "Value must be between 0 and 1000" << RESET "\n\n\n";
			continue;
		}
		map.insert(std::pair<string, double>(key, value));
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */