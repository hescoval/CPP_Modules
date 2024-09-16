#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include "general.hpp"
#include <deque>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	using std::stack<T, Container>::c;
	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();


		MutantStack &		operator=( MutantStack const & rhs );

	private:

};

#endif /* ***************************************************** MUTANTSTACK_H */