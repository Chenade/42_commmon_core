#include "Base.hpp"

Base*   generate(void)
{
    if (std::rand() % 3 == 0)
        return (new A);
    else if (std::rand() % 3 == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void    identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
	
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

/*
	dynamic_cast is a type of casting operation in C++ that allows you to safely 
	convert pointers or references to objects from one class to another class within 
	an inheritance hierarchy. It is used when you need to determine at runtime if a 
	particular pointer/reference is pointing to an object of a specific derived class 
	or not.
*/