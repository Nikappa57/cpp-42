#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(const std::string & name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "FragTrap " << i.getName() << " has " << i.getHitPoints() << " hit points, "
		<< i.getEnergyPoints() << " energy points and does " << i.getAttackDamage() << " damage points.";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::attack(const std::string& target) {
	if (!this->check_if_alive())
		std::cout << "FragTrap " << this->name << " is dead!" << std::endl;
	else if (this->check_consume_energy())
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (!this->check_if_alive())
		std::cout << "FragTrap " << this->name << " is dead!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << ": high fives guys!";
	std::cout << std::endl;
}


/* ************************************************************************** */