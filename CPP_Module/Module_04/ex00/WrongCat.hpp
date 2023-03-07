# ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat& cat);
		~WrongCat();

		WrongCat& operator=(const WrongCat& cat);

		void makeSound() const;
};

#endif