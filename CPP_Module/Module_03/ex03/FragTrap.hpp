
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap( std::string name );
		~FragTrap();

		void    attack(std::string const& target);
		void    highFivesGuys();
};

#endif