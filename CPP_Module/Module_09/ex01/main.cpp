#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"OPERATION\"\n";
		return 1;
	}
	
	try
	{
		int res = RPN::ResolveExpression(argv[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
