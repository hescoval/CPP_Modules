#ifndef RPN_HPP
# define RPN_HPP

#include "general.hpp"
#include <stack>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		virtual ~RPN();

		RPN &		operator=( RPN const & rhs );

		class InvalidOperationException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidCharacterException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidAmountOfOperationsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		static double		evaluate(string input);
	private:
		static void			evaluate_operation(std::stack<double> &stack, char op);
		static void			input_treatment(string &input);
};

#endif /* ************************************************************* RPN_H */