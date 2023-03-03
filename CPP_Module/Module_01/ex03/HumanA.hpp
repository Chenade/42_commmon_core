
# ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

using namespace std;

class HumanA
{
	private:
		string _name;
		Weapon &_weapon;
	
	public:
		HumanA(string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif