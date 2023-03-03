#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Zombie
{
	private:
		string _name;
		
	public:
		Zombie();
		~Zombie();
		void    announce( void );
		void    setName( string name );
};

Zombie* zombieHorde( int N, string name );

#endif