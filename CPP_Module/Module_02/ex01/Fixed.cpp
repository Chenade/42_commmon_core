
#include "Fixed.hpp"

using namespace std;

Fixed::Fixed(void) : _fixedPointValue(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits )))
{
    cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    cout << "Copy constructor called" << endl;
    *this = rhs;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
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
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << _fractionalBits);
}

int Fixed::toInt (void) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}