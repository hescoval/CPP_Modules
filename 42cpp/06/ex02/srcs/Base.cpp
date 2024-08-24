#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"

Base::Base()
{
    funcArray[0] = &Base::make_A;
    funcArray[1] = &Base::make_B;
    funcArray[2] = &Base::make_C;
}

Base::~Base(){}

Base*       Base::make_A()
{
    cout << GREEN "Created Derived class A" RESET << endl;
    return new A();
}

Base*       Base::make_B()
{
    cout << GREEN "Created Derived class B" RESET << endl;
    return new B();
}

Base*       Base::make_C()
{
    cout << GREEN "Created Derived class C" RESET << endl;
    return new C();
}

Base*       Base::generate(void)
{
    std::srand(time(0));

    int random_value = std::rand() % 3;
    return (this->*funcArray[random_value])();
}

void        Base::identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL)
        cout << CYAN "Subclass A detected!" RESET << endl;
    if(dynamic_cast<B*>(p) != NULL)
        cout << CYAN "Subclass B detected!" RESET << endl;
    if(dynamic_cast<C*>(p) != NULL)
        cout << CYAN "Subclass C detected!" RESET << endl;
}

void        Base::identify(Base& p)
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