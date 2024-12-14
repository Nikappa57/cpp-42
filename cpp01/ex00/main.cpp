#include "Zombie.hpp"

int	main(void) {
	Zombie *z;

	std::cout << "Creating new zombie (stack)" << std::endl;
	randomChump("Zombie1");
	std::cout << "Finished creating new zombie (stack)" << std::endl;

	std::cout << "Creating new zombie (heap)" << std::endl;
	z = newZombie("Zombie2");
	z->announce();
	delete z;
	std::cout << "Finished creating new zombie (heap)" << std::endl;

	return 0;
}
