#include "Harl.hpp"

using namespace std;

Harl::Harl()
{
	cout << "Harl created" << endl;
}

Harl::~Harl()
{
	cout << "Harl destroyed" << endl;
}

void Harl::debug( void )
{
    cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info( void )
{
    cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << endl;
}

void Harl::warning( void )
{
    cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month" << endl;
}

void Harl::error( void )
{
    cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain( string level )
{
    string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i].compare(level))
        i++ ;
    switch (i)
    {
    case    0: 
        this->debug();
    case    1: 
        this->info();
    case    2: 
        this->warning();
    case    3: 
        this->error();
        break ;
    default:
        cout << "[ Probably complaining about insignificant problems ]" << endl;
    }
}