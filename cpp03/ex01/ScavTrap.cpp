#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " created" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	o << "ScavTrap " << i.getName() << " has " << i.getHitPoints() << " hit points, "
		<< i.getEnergyPoints() << " energy points and does " << i.getAttackDamage() << " damage points.";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string& target) {
	if (!this->check_if_alive())
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
	else if (this->check_consume_energy())
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (!this->check_if_alive())
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}

/* ************************************************************************** */