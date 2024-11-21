#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB() {}

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