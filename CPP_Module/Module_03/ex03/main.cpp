
#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap dt("dt");
    DiamondTrap dt2(dt);
    DiamondTrap dt3(".");

    dt.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();

    dt.attack("the air");
    dt.takeDamage(10);
    dt.beRepaired(10);

    return 0;
}