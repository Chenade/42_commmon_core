#include "easyfind.hpp"
#include <vector>
#include <list>

int main( int ac, char ** av )
{
	if (ac != 2)
	{
		std::cout << "Error: Usage: ./easyfind <nbr to find>" << std::endl;
		return (1);
	}

	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector<int>      vect( arr, arr + sizeof( arr ) / sizeof(int) );
	std::list<int>        list( arr, arr + sizeof( arr ) / sizeof(int) );

	try
	{
		easyfind(vect, std::atoi(av[1]));
		std::cout << av[1] << " found in vector container" << std::endl;
		easyfind(list, std::atoi(av[1]));
		std::cout << av[1] << " found in list container" << std::endl;
	} catch( const std::exception& e ) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}