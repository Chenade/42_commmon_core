
#include "Zombie.hpp"

using namespace std;
int main( void ) {
    string name;

    cout << "Creating zombie on the stack." << endl;
    cout << "Zombie name: " << flush;
    cin >> name;

    Zombie zombie1(name);
    zombie1.announce();
    
    cout << "Creating zombie on the heap." << endl;
    cout << "Zombie name: " << flush;
    cin >> name;

    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    cout << "Calling randomChump()." << endl;
    randomChump("randi");
    return (0);
}