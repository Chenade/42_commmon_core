#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

	std::cout << "[FragTrap] - constructor called. name : " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] - deconstructor called. name : " << this->_name << std::endl;
}

void    FragTrap::attack(std::string const& target)
{
    if (this->_energyPoints <= 0) {
        std::cout << "[FragTrap] - " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "[FragTrap] - " << this->_name << " attacks " << target << " at range, causing " << this->_attackDamage << " points of damage !" << std::endl;
    this->_energyPoints -= 1;
}

void    FragTrap::highFivesGuys()
{
	if ( this->_energyPoints <= 0 ) {
        std::cout << "[FragTrap] - " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "[FragTrap] - " << this->_name << " Highfive!!" << std::endl;
	--this->_energyPoints;
}