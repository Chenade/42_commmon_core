#include "Zombie.hpp"

using namespace std;

Zombie::Zombie(string name)
{
	this->name = name;
	cout << "Zombie " << this->name << " has been created." << endl;
}

Zombie::~Zombie()
{
	cout << "Zombie " << this->name << " has been destroyed." << endl;
}

void Zombie::announce()
{
	cout << this->name << ": Braiiiiiiinnnssss..." << endl;
}
