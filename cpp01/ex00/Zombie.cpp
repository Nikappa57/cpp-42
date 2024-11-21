#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie(std::string name) : name(name) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is dead" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
