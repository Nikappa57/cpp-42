#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(const std::string& type) : type(type) {
	std::cout << "Constructor called for Weapon" << std::endl;
}


Weapon::~Weapon() {
	std::cout << "Destructor called for Weapon" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Weapon::getType(void) const {
	return (this->type);
}

void Weapon::setType(const std::string& type) {
	this->type = type;
}

/* ************************************************************************** */