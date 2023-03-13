#include "Span.hpp"

int main(int argc, char **argv)
{	
	std::srand(time(NULL));
	
	int n = 5;
	if (argc == 2)
		n = atoi(argv[1]);
	Span sp = Span(n);

	try
	{
		for (int i = 0; i < n; i ++)
			sp.addNumber((rand() % n) + 1);
		sp.print();
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Shortest Span: " <<  sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}