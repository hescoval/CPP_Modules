#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include "general.hpp"
#include <deque>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:

		MutantStack(){}
		MutantStack( MutantStack const & src ){*this = src;}
		~MutantStack(){}

		typedef typename Container::iterator iterator;
		iterator	begin()	{	return this->c.begin();	};
		iterator	end()	{	return this->c.end();	};


		MutantStack &		operator=( MutantStack const & rhs );

	private:

};

#endif /* ***************************************************** MUTANTSTACK_H */