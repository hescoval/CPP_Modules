#ifndef BASE_HPP
# define BASE_HPP

# include "general.hpp"

class Base
{
    public:
        Base();
        virtual ~Base();
};
        Base*       make_A();
        Base*       make_B();
        Base*       make_C();
        Base*       generate(void);
        void        identify(Base* p);
        void        identify(Base& p);

#endif