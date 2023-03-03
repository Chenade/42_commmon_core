
#include "Harl.hpp"

using namespace std;

int main( void )
{
    string	input;
    Harl	harl;

	cout << "Level: DEBUG, INFO, WARNING, ERROR, EXIT" << endl;
    do
    {
        cout << "Enter a level: ";
        cin >> input;
        harl.complain(input);
    } while (input.compare("EXIT"));

    return (0);
}