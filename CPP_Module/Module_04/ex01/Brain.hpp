# ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _idea[100];

	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();

		Brain& operator=(const Brain& brain);
};

#endif