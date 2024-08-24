#include "headers/general.hpp"
#include "headers/Base.hpp"

void simple_dynamic_cast_test()
{
    Base p;

    Base *derived = p.generate();

    derived->identify(*derived);

    cout << RED "\nPointer Test\n" RESET << endl;
    derived->identify(derived);

    delete derived;
}

int main()
{
    simple_dynamic_cast_test();
}