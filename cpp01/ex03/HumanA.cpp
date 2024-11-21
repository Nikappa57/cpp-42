#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(const std::string &name, Weapon& weapon) : name(name) , weapon(weapon) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

/* ************************************************************************** */