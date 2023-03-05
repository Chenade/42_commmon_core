
#include "Fixed.hpp"

using namespace std;

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
	cout << "Default constructor called" << endl;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	cout << "Copy constructor called" << endl;
    this->setRawBits(fixed.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
	return *this;	
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}