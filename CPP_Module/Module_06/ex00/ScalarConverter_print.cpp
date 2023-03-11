#include "ScalarConverter.hpp"

bool    ScalarConverter::isAlpha( void ) const
{
    if ( ( _impossible ) || ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
        || ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
        || ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ) 
        || ( _str.compare( "-inff" ) == 0 ) || ( _str.compare( "-inff" ) == 0 )  
        || ( _str.compare( "+inff" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) ) {
            return true;
    } 
    return false;
}

bool    ScalarConverter::isChar( void ) const
{
    return _str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]);
}

bool    ScalarConverter::isInt(void) const
{
    int    j = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( !std::isdigit(_str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(void) const
{
    if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int j = 0;
    int found = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

bool    ScalarConverter::isFloat (void) const
{
	if ( _str.find( '.' ) == std::string::npos || _str.at(_str.length()-1) != 'f'
        || _str.find( '.' ) == 0 || _str.find( '.' ) == _str.length() - 2 )
        return false;
    int found = 0;
    int j = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length() - 1; i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

void    ScalarConverter::printChar(void) const
{
    if (this->isAlpha())
        std::cout << "Impossible";
    else if (!(_n >= 0 && _n <= 255 && std::isprint(static_cast<unsigned char>(_n))))
        std::cout << "None displayable";
    else
        std::cout << "'" << getC() << "'";
    std::cout << std::endl;
}

void    ScalarConverter::printInt(void) const
{
    if (this->isAlpha())
        std::cout << "Impossible";
    else
        std::cout << getI();
    std::cout << std::endl;
}

void    ScalarConverter::printFloat(void) const
{
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 )
        std::cout << "nanf";
    else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 )
        std::cout << "+inff";
    else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 )
        std::cout << "-inff";
    else if ( _impossible )
        std::cout << "Impossible";
    else {
        if ( _f - static_cast< int > ( _f ) == 0 ) {
            std::cout << _f << ".0f";
        } else {
            std::cout << getF() << "f";
        }
    }
    std::cout << std::endl;
}

void    ScalarConverter::printDouble(void) const
{
    if (_str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 )
        std::cout << "nan";
    else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 )
        std::cout << "+inf";
    else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 )
        std::cout << "-inf";
    else if ( _impossible )
        std::cout << "Impossible";
    else {
        if ( _d - static_cast< int > ( _d ) == 0 ) {
            std::cout << _d << ".0";
        } else {
            std::cout << getD() << "f";
        }
    }
    std::cout << std::endl;
}