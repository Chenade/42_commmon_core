# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int 	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int 	_attackDamage;

	public:
		ClapTrap(const std::string& name);
    	ClapTrap(const ClapTrap &);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool checkEnergyPoint();
};

#endif