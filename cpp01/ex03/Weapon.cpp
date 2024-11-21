#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(const std::string& type) : type(type) {}


Weapon::~Weapon() {}

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