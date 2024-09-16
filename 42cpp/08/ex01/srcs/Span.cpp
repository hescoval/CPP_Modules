#include "../headers/Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int N)
{
	_containerSize = N;
}

Span::Span( const Span & src )
{
	_containerSize = src._containerSize;
	_container = src._container;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this == &rhs )
		return *this;

	_containerSize = rhs._containerSize;
	_container = rhs._container;

	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Span::maxSizeReached::what() const throw()
{
	return "Max size reached, can't add more numbers";
}

const char* Span::rangeSize_TooBig::what() const throw()
{
	return "Adding this range would exceed the max size";
}

const char* Span::InvalidRanges::what() const throw()
{
	return "Iterators invalid, end would not be reached";
}



int Span::shortestSpan()
{
	if(_container.size() < 2)
		return 0;

	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1] - sorted[i] < shortest)
			shortest = sorted[i + 1] - sorted[i];
	}

	return shortest;
}

int Span::longestSpan()
{
	if(_container.size() < 2)
		return 0;

	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());

	return abs(sorted[sorted.size() - 1] - sorted[0]);
}

void	Span::addNumber(int n)
{
	if (_container.size() == _containerSize)
		throw Span::maxSizeReached();

	_container.push_back(n);

	std::sort(_container.begin(), _container.end());
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if(std::distance(begin, end) < 0)
		throw Span::InvalidRanges();

	if (_container.size() + std::distance(begin, end) > _containerSize)
		throw Span::maxSizeReached();

	_container.insert(_container.end(), begin, end);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */