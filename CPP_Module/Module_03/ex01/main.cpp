# include "ScavTrap.hpp"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	ScavTrap st("ScavTrap_test");
    ScavTrap st2(st);

    st.attack("the air");
    st.takeDamage( 10 );
    st.beRepaired( 10 );
    st.guardGate();
	
	return (0);
}