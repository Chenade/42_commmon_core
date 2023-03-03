#include "HumanB.hpp"

HumanB::HumanB(string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	cout << "HumanB destroyed" << endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
        cout << _name << " attacks with their " << this->_weapon->getType() << endl;
    } else {
        cout << _name << " doesn't have a weapon to attack." << endl;
    }
}