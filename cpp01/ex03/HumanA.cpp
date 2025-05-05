#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(const std::string &name, Weapon& weapon) : name(name) , weapon(weapon) {
	std::cout << "Constructor called for HumanA" << std::endl;
	std::cout << this->name << " is created" << std::endl;
	std::cout << "Weapon type: " << this->weapon.getType() << std::endl;
	std::cout << "-------------------------" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA() {
	std::cout << "Destructor called for HumanA" << std::endl;
	std::cout << this->name << " is destroyed" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

/* ************************************************************************** */