#include "FragTrap.hpp"

int main( void )
{
    FragTrap ft("FragTrap_test");
    FragTrap ft2(ft);

    ft.attack("the air");
    ft.takeDamage(10);
    ft.beRepaired(10);
    ft.highFivesGuys();

    return 0;
}