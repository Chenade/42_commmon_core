#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Zombie {
	private:
		string name;
	public:
		Zombie(string name);
		~Zombie();
		void announce();
};

Zombie  *newZombie( string name );
void    randomChump( string name );

#endif