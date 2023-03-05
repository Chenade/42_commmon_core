
#include "Fixed.hpp"

using namespace std;

// ------------------- Constructor ------------------- //
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

Fixed::Fixed(const Fixed& child)
{
    cout << "Copy constructor called" << endl;
    *this = child;
}

// ------------------- Deconstructor ------------------- //
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

// ------------------- Deconstructor ------------------- //
Fixed& Fixed::operator=(const Fixed& fixed)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
	return *this;	
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    return Fixed(this->toFloat() + fixed.toFloat());

}

Fixed Fixed::operator*(const Fixed& fixed)
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

// ------------------- Comparsion ------------------- //
bool Fixed::operator<(const Fixed& fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator<=(const Fixed& fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>(const Fixed& fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator>=(const Fixed& fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(const Fixed& fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed& fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

// --------------- Increment / Decrement ----------------- //
Fixed&   Fixed::operator++( void ) {
    ++this->_fixedPointValue;
    return (*this);
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp(*this);
    tmp._fixedPointValue = this->_fixedPointValue++;
    return (tmp);
}

Fixed& Fixed::operator--( void ) {
    --this->_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator--( int ) {
    Fixed tmp(*this);
    tmp._fixedPointValue = this->_fixedPointValue--;
    return (tmp);
}

// ------------------- Function ------------------- //
Fixed& 	Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (b);
    return (a);
}

const Fixed& 	Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (b);
    return (a);
}

Fixed& 	Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

const Fixed& 	Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
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

// Others
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}