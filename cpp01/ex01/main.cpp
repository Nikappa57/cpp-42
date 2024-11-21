#include "Zombie.hpp"

int	main(void) {
	int		n;
	Zombie	*horde;

	std::cout << "Number of zombies in the horde: ";
	std::cin >> n;

	if (std::cin.fail()) {
		std::cerr << "Invalid input" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Creating a horde of " << n << " zombies" << std::endl;

	horde = zombieHorde(n, "Zombie");

	std::cout << "Zombie horde created" << std::endl;

	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
