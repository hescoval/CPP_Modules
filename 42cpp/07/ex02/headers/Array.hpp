#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include "general.hpp"

template <typename T>
class Array
{

	public:

		Array();
		Array( unsigned int n );
		Array( Array const & src );
		~Array();

		Array &		operator=( Array const & rhs );

	private:
		T*		_array;
		size_t	_size;
};

#include "Array.tpp"

#endif /* *********************************************************** ARRAY_H */