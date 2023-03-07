#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
    std::cout << "[" << this->_type << "] - constructor called" << std::endl;
    
}

Dog::~Dog( void )
{
    std::cout << "[" << this->_type << "] - destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "[" << this->_type << "] - Woof!" << std::endl;
}