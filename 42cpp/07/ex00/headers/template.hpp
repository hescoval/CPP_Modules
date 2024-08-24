#include "general.hpp"

template <typename T>
T max(T x, T y)
{
    return (x <= y ? y : x);
}

template <typename T>
T min(T x, T y)
{
    return (x >= y ? y : x);
}

template <typename T>
void swap(T& x, T& y)
{
    T swap;
    swap = x;
    x = y;
    y = swap;
}