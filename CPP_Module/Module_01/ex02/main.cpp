
#include <iostream>

using namespace std;

int main( void ) 
{
    string str = "HI THIS IS BRAIN";
    
    string *stringPTR = &str;
    string &stringREF = str;

    cout << "This is the address of the string: ";
    cout << &str << endl;
    cout << "This is the address of the pointer to string: ";
    cout << stringPTR << endl;
    cout << "This is the address of the reference to string: ";
    cout << &stringREF << endl;

    cout << "This is the value of the string: ";
    cout << str << endl;
    cout << "This is the value of the pointer to string: ";
    cout << *stringPTR << endl;
    cout << "This is the value of the reference to string: ";
    cout << stringREF << endl;

    return (0);
}