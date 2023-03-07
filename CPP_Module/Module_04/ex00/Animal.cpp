#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] - constructor called." << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "[Animal] - constructor copied called." << std::endl;
	*this = animal;
}

Animal::Animal(std::string type)
{
	std::cout << "[Animal] - constructor with type called." << std::endl;
	this->_type = type;
}


Animal::~Animal()
{
	std::cout << "[Animal] - destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "[Animal] - Copy assignment operator called" << std::endl;
    if (this != &animal)
        this->_type = animal.getType();
    return *this;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "[Animal] - " << __func__ << std::endl;
}