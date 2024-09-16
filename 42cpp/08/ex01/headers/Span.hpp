#ifndef SPAN_HPP
# define SPAN_HPP

# include "general.hpp"

class Span
{

	public:

		Span(unsigned int N = 0);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);


		class maxSizeReached : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class rangeSize_TooBig : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidRanges : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		size_t	_containerSize;
		std::vector<int> _container;
};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */