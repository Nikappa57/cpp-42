# include <iostream>
# include "ClapTrap.hpp"

int main( void ) {
	ClapTrap claptrap("marius");

	std::cout << claptrap << std::endl;
	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(2);
	claptrap.takeDamage(5);
	claptrap.beRepaired(10);

	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");

	return 0;
}