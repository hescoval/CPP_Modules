#include "headers/general.hpp"
#include "headers/BitcoinExchange.hpp"

void incorrect_usage()
{
	cout << RED << "Usage: ./btc (file name)" << RESET << endl;
	exit(1);
}

int main(int ac, char **av)
{
	if(ac != 2)
		incorrect_usage();
    string crypto_file = "data.csv";
	string user_file = string(av[1]);
	char user_file_delim = '|';
	char crypto_delim = ',';

    BitcoinExchange exchange(crypto_file, user_file, user_file_delim, crypto_delim);
	exchange.check_holdings();
}