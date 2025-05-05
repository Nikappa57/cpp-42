#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {
	std::cout << "Constructor called for HumanB" << std::endl;
	std::cout << this->name << " is created" << std::endl;
	std::cout << "Weapon type: none" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB() {
	std::cout << "Destructor called for HumanB" << std::endl;
	std::cout << this->name << " is destroyed" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanB::attack(void) const {
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType() << std::endl;
	else
		std::cout << "hands :(" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

/* ************************************************************************** */