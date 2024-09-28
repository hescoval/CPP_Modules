#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "general.hpp"
# include "FileManager.hpp"
# include <map>
# include <ctime>

enum potential_errors
{
	DATE_MATCH_NOT_FOUND = -1
};

class BitcoinExchange
{
	public:

		BitcoinExchange(string crypto_file = "data.csv", string user_file = "input.txt", char delim = '|', char crypto_delim = ',');
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		void							check_holdings();

	private:
		void							find_date_match(string date, double user_amount, double& value_at_date);
		void 							line_key_value_validations(string key, string value_string);
		void							check_date_format(std::tm date);
		bool							is_leap_year(int year);
		void							validate_date(string date);
		std::tm 						string_to_date(const std::string& dateStr);
		void							check_gibberish(string str);
		void							set_values(std::multimap<string, double>& map, string file_name, char delim);
		std::multimap<string, double>	crypto_values;
		std::multimap<string, double> 	user_holdings;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */