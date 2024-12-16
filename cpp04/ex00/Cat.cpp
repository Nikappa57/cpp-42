#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const
{
	std::cout << "Miao..." << std::endl;
}


/* ************************************************************************** */