#include "Zombie.hpp"

using namespace std;

Zombie::Zombie( void )
{
}

Zombie::~Zombie( void )
{
    cout << "Zombie " << this->_name << " has been destroyed." << endl;
}

void    Zombie::announce( void )
{
    cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void    Zombie::setName( string name )
{
    this->_name = name;
}
