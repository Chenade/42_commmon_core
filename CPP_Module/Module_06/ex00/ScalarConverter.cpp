#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
    this->_impossible = false;
	this->_c = '\0';
	this->_n = 0;
	this->_f = 0.0f;
	this->_d = 0.0;
}

ScalarConverter::ScalarConverter( const ScalarConverter& src )
{
	*this = src;
}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this != &src)
	{
		this->_n = src.getI();
		this->_f = src.getF();
		this->_c = src.getC();
	}
	return *this;
}

char    ScalarConverter::getC(void) const
{
	return (this->_c);
}

void    ScalarConverter::setC(char c)
{
	this->_c = c;
}

int    ScalarConverter::getI(void) const
{
	return (this->_n);
}

void    ScalarConverter::setI(int n)
{
	this->_n = n;
}

float   ScalarConverter::getF(void) const
{
	return (this->_f);
}

void    ScalarConverter::setF(float f)
{
	this->_f = f;
}

double  ScalarConverter::getD(void) const
{

	return (this->_d);
}

void    ScalarConverter::setD(double d)
{
	this->_d = d;
}

std::string ScalarConverter::getStr(void) const
{
	return this->_str;
}

void ScalarConverter::setStr(std::string str)
{
	this->_str = str;
	this->setType();
	if ( getType() == NONE )
		throw ScalarConverter::ScalarConverterException();
}

void    ScalarConverter::setType(void)
{
	if (isChar())
		_type = CHAR;
	else if (isInt())
		_type = INT;
	else if (isFloat())
		_type = FLOAT;
	else if (isDouble())
		_type = DOUBLE;
	else if (isAlpha())
		_type = LITERALS;
	else
		_type = NONE;
}

e_type  ScalarConverter::getType( void ) const
{
	return this->_type;
}