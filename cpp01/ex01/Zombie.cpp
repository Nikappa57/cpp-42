#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is dead" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
