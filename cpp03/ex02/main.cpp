# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

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
	std::cout << "----------------------------------------" << std::endl;
	{
		FragTrap fragtrap("vittorius");
		std::cout << fragtrap << std::endl;
		fragtrap.attack("enemy");
		fragtrap.takeDamage(5);
		fragtrap.beRepaired(2);
		fragtrap.highFivesGuys();
	}
	return 0;
}