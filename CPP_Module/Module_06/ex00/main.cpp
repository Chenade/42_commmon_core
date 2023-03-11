#include "ScalarConverter.hpp"

int main( int argc, char ** argv)
{
	if ( argc != 2 ) {
		std::cout << "Usage: ./convert number" << std::endl;
		return (1);
	}

	ScalarConverter c;

	try
	{
		c.setStr(argv[1]);
		c.convert();

		std::cout << c;
	}
	catch( const std::exception& e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}