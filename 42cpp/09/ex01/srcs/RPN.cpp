#include "../headers/RPN.hpp"	

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN(){}

RPN::RPN( const RPN & src ){(void)src;}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		RPN::evaluate_operation(std::stack<double> &stack, char op)
{
	if(stack.size() < 2)
		throw RPN::InvalidOperationException();
	double a = stack.top();
	stack.pop();
	double b = stack.top();
	stack.pop();

	switch(op)
	{
		case '+':
			stack.push(b + a);
			break;
		case '-':
			stack.push(b - a);
			break;
		case '*':
			stack.push(b * a);
			break;
		case '/':
		{
			if(a == 0)
				throw RPN::DivisionByZeroException();
			stack.push(b / a);
			break;
		}
	}
}

void		RPN::input_treatment(string &input)
{

	const string operators = "+-*/";
	trim(input);
	replace_whitespace(input);
	if(input.find_first_not_of("0123456789+-*/ ") != string::npos)
		throw RPN::InvalidCharacterException();

	remove_consecutives(input, ' ');
}

double		RPN::evaluate(string input)
{
	std::stack<double> stack;
	const string operators = "+-*/";

	input_treatment(input);

	for(size_t i = 0; i < input.size(); i++)
	{
		if(isdigit(input[i]))
		{
			double to_push = strtod(input.substr(i).c_str(), NULL);
			if(to_push > 9)
				throw RPN::InvalidNumberException();
			stack.push(to_push);
		}

		if(operators.find(input[i]) != string::npos)
			evaluate_operation(stack, input[i]);
	}

	if(stack.size() != 1)
		throw RPN::InvalidAmountOfOperationsException();
	
	return(stack.top());
}


/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/

const char *RPN::InvalidOperationException::what() const throw()
{
	return "Invalid Operation";
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return "Division by zero";
}

const char *RPN::InvalidCharacterException::what() const throw()
{
	return "Invalid character found";
}

const char *RPN::InvalidNumberException::what() const throw()
{
	return "Invalid number found";
}

const char *RPN::InvalidAmountOfOperationsException::what() const throw()
{
	return "Invalid amount of operations";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */