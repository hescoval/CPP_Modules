#include "headers/general.hpp"
#include "headers/Base.hpp"
#include "headers/A.hpp"
#include "headers/B.hpp"
#include "headers/C.hpp"

Base*       make_A()
{
    cout << GREEN "Created Derived class A" RESET << endl;
    return new A();
}

Base*       make_B()
{
    cout << GREEN "Created Derived class B" RESET << endl;
    return new B();
}

Base*       make_C()
{
    cout << GREEN "Created Derived class C" RESET << endl;
    return new C();
}

Base*       generate(void)
{
    std::srand(time(0));
    Base* (*funcArray[3])();

    funcArray[0] = &make_A;
    funcArray[1] = &make_B;
    funcArray[2] = &make_C;
    int random_value = std::rand() % 3;
    return (*funcArray[random_value])();
}

void        identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL)
        cout << CYAN "Subclass A detected!" RESET << endl;
    if(dynamic_cast<B*>(p) != NULL)
        cout << CYAN "Subclass B detected!" RESET << endl;
    if(dynamic_cast<C*>(p) != NULL)
        cout << CYAN "Subclass C detected!" RESET << endl;
}

void        identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        cout << CYAN "Subclass A detected!" RESET << endl;
    }
    catch(std::exception& e)
    {

    }
    try
    {
        (void)dynamic_cast<B&>(p);
        cout << CYAN "Subclass B detected!" RESET << endl;
    }
    catch(std::exception& e)
    {

    }
    try
    {
        (void)dynamic_cast<C&>(p);
        cout << CYAN "Subclass C detected!" RESET << endl;
    }
    catch(std::exception& e)
    {

    }
}

void simple_dynamic_cast_test()
{
    Base *derived = generate();

    identify(*derived);

    cout << RED "\nPointer Test\n" RESET << endl;
    identify(derived);

    delete derived;
}

int main()
{
    simple_dynamic_cast_test();
}