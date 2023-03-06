#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] - constructor called. name : " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] - deconstructor called. name : " << this->_name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &rhs ) {
    *this = rhs;
    std::cout << "[ClapTrap] - " << this->_name << " has been copied with copy constuctor." << std::endl;
}

bool ClapTrap::checkEnergyPoint()
{
	if (this->_energyPoints <= 0)
	{
        std::cout << "[ClapTrap] - " << _name << " is out of energy!" << std::endl;
		return (false);
	}
	else
		return (true);
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if ((_hitPoints - amount) <= 0)
    {
        std::cout << "[ClapTrap] - " << _name << " is dead!" << std::endl;
        return;
    }
    std::cout << "[ClapTrap] - " << _name << " takes " << amount << " damage!" << std::endl;
    _hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (!this->checkEnergyPoint())
		return ;
    std::cout << "[ClapTrap] - " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	--this->_energyPoints;
    _hitPoints += amount;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->checkEnergyPoint())
		return ;
	std::cout << "[ClapTrap] - "
				<< this->_name
				<< " attacks "
				<< target
				<< ", causing "
				<< this->_attackDamage
				<< " points of damage!"
				<< std::endl;
	--this->_energyPoints;
}