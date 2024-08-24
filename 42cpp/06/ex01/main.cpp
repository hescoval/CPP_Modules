#include "headers/Data.hpp"
#include "headers/general.hpp"
#include "headers/Serializer.hpp"

static void simple_reinterpret_test()
{
    Data *data_pointer = new Data();
    uintptr_t casted_uint_ptr;
    Data *casted_data_ptr;

    cout << GREEN "Address before Serializing Data Pointer: " CYAN << data_pointer << RESET << endl;;
    casted_uint_ptr = Serializer::serialize(data_pointer);
    cout << GREEN "Address After Serialization: " << CYAN << casted_uint_ptr << RESET << endl;
    casted_data_ptr = Serializer::deserialize(casted_uint_ptr);
    cout << GREEN "Address After Deserialization: " << CYAN << casted_data_ptr << RESET << endl;

    cout << endl;
    cout << CYAN << casted_data_ptr->name << " Is aged " << casted_data_ptr->age << RESET << endl;
    delete(casted_data_ptr);
}  

int main()
{
    simple_reinterpret_test();
}