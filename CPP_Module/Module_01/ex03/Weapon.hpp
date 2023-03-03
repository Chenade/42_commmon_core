
# ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using namespace std;

class Weapon
{
	private:
		string type;
	
	public:
		Weapon(string type);
		~Weapon();
		const string &getType();
		void setType(string type);
};

#endif	