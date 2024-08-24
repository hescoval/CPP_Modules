#ifndef BASE_HPP
# define BASE_HPP

# include "general.hpp"

class Base
{
    private:
        Base*   (Base::*funcArray[3])(void);

    public:
        Base();
        virtual ~Base();
        Base*   generate(void);

        Base*      make_A();
        Base*      make_B();
        Base*      make_C();
        void    identify(Base* p);
        void    identify(Base& p);
};

#endif