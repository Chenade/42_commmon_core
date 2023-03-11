#include "ScalarConverter.hpp"

bool ScalarConverter::isImpossible( void )
{
    try
    {
        if (_type == INT) {
            _n = atoi(_str.c_str());
        } else if (_type == FLOAT) {
            _f = static_cast<float>(atof( _str.c_str() ));
        } else if (_type == DOUBLE) {
            _d = atof( _str.c_str() );
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error message: " << e.what() << std::endl;
        _impossible = true;
        return true;
    }
    return false;
}

void ScalarConverter::convert(void)
{
    if (isImpossible())
        return;
    switch (_type)
    {
        case CHAR:
            _c = _str[0];
            _n = static_cast<int>(_c);
            _f = static_cast<float>(_c);
            _d = static_cast<double>(_c);
            break;
        case INT:
            _n = atoi(_str.c_str());
            _f = static_cast<float>(_n);
            _d = static_cast<double>(_n);
            _c = static_cast<char>(_n);
            break;
        case FLOAT:
            _f = static_cast<float>(atof(_str.c_str()));
            _n = static_cast<int>(_f);
            _d = static_cast<double>(_f);
            _c = static_cast<char>(_f);
            break;
        case DOUBLE:
            _d = atof( _str.c_str() );
            _n = static_cast<int>(_d);
            _f = static_cast<float>(_d);
            _c = static_cast<char>(_d);
            break;
        default:
            break;
    }
}


std::ostream&    operator<<(std::ostream& o, const ScalarConverter& rhs)
{
    o << "char: "; rhs.printChar();
    o << "int: "; rhs.printInt();
    o << "float: "; rhs.printFloat();
    o << "double: "; rhs.printDouble();
    return o;
}