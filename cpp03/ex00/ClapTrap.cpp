#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(const std::string & name)
	: name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs ) {
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "ClapTrap " << i.getName() << " has " << i.getHitPoints() << " hit points, "
		<< i.getEnergyPoints() << " energy points and does " << i.getAttackDamage() << " damage points.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/* public */

void ClapTrap::attack(const std::string& target) {
	if (!this->check_if_alive())
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
	else if (this->check_consume_energy())
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->check_if_alive())
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
	else {
		this->hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} if (!this->check_if_alive())
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	bool is_alive = this->check_if_alive();
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
	if (!is_alive && this->check_if_alive())
		std::cout << "ClapTrap " << this->name << " is alive again!" << std::endl;
}

/* private */

bool ClapTrap::check_consume_energy(void) {
	if (this->energy_points > 0) {
		this->energy_points--;
		return true;
	}
	return false;

}

bool ClapTrap::check_if_alive(void) const {
	return this->hit_points > 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName() const { return name; }
int ClapTrap::getHitPoints() const { return hit_points; }
int ClapTrap::getEnergyPoints() const { return energy_points; }
int ClapTrap::getAttackDamage() const { return attack_damage; }

/* ************************************************************************** */