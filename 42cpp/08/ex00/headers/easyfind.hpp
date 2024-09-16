#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "general.hpp"
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif
