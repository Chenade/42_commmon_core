# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

using namespace std;

class HumanB
{
	private:
		string _name;
		Weapon *_weapon;
	
	public:
		HumanB(string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif