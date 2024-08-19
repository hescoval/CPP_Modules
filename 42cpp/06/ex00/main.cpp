#include "headers/general.hpp"
#include "headers/ScalarConverter.hpp"

static void correct_usage()
{
    cout << RED << "Usage: " << BRIGHT_RED << "./convert value_to_convert" << RESET << endl;
    exit(1);
}

int        main(int ac, char **av)
{
    if (ac != 2)
        correct_usage();

    ScalarConverter::convert(string(av[1]));
}