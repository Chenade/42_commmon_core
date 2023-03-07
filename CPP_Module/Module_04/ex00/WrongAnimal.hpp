# ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& animal);
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		
		WrongAnimal& operator=(const WrongAnimal& animal);
		
		std::string getType() const;
		virtual void makeSound(void) const;
};

#endif 