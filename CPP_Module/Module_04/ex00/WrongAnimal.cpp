#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] - constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal)
{
	std::cout << "[WrongAnimal] - constructor copied called." << std::endl;
	*this = animal;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "[WrongAnimal] - constructor with type called." << std::endl;
	this->_type = type;
}


WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] - destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
    std::cout << "[WrongAnimal] - Copy assignment operator called" << std::endl;
    if (this != &animal)
        this->_type = animal.getType();
    return *this;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] - " << __func__ << std::endl;
}