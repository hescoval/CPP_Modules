#include "general.hpp"

template <typename T>
void print(T &elem)
{
    cout << CYAN << "\n" << elem; 
}

template <typename T>
void print(const T &elem)
{
    cout << CYAN << "\n" << elem; 
}

template <typename T>
void iter(T* array, size_t array_size, void (*func)(T &))
{

    for(size_t i = 0; i < array_size; i++)
        func(array[i]);
}

template <typename T>
void iter(const T* array, size_t array_size, void (*func)(T const &))
{
    for(size_t i = 0; i < array_size; i++)
        func(array[i]);
}   