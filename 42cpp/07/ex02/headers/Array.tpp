#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array( unsigned int n ) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array( const Array<T> & src ) : _array(new T[src._size]), _size(src._size)
{
    for (size_t i = 0; i < _size; ++i) 
	{
        _array[i] = src._array[i];
    }
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) 
{
    if (this != &rhs) 
    {
        delete[] _array;
        _size = rhs._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) 
        {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */