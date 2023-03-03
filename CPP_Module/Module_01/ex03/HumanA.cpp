#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void	HumanA::attack()
{
	if (this->_weapon.getType() != "") {
        cout << _name << " attacks with their " << this->_weapon.getType() << endl;
    } else {
        cout << _name << " doesn't have a weapon to attack." << endl;
    }
}