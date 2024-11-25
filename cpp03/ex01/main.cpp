# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"



int main( void ) {

	{
		ClapTrap claptrap("marius");
		std::cout << claptrap << std::endl;
		claptrap.attack("enemy");
		claptrap.takeDamage(5);
		claptrap.beRepaired(2);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		ScavTrap scavtrap("valerius");
		std::cout << scavtrap << std::endl;
		scavtrap.attack("enemy");
		scavtrap.takeDamage(5);
		scavtrap.beRepaired(2);
		scavtrap.guardGate();
	}
	return 0;
}