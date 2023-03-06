
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    
    std::cout << "[DiamondTrap] - constructor called. name : " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] - deconstructor called. name : " << this->_name << std::endl;
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "[DiamondTrap] - I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
