# include "ClapTrap.hpp"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	ClapTrap ct("ClapTrap_test");

	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.beRepaired(10);
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	ct.attack("target");
	
	return (0);
}