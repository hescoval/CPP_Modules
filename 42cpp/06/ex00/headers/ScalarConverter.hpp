#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "general.hpp"
#include "sstream"

class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		virtual ~ScalarConverter() = 0;
		static void convert(string str);	

		ScalarConverter &		operator=( ScalarConverter const & rhs );

	private:
		static void 		printChar(char c, string str);
		static void 		printInt(int num, string str);
		static void 		printFloat(float num, string str);
		static void 		printDouble(double num, string str);

		static bool		    check_Char(string str);
		static bool		    check_Int(string str);
		static bool		    check_Float(string str);
		static bool		    check_Double(string str);

		static bool		    check_pseudo(string str);
};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */