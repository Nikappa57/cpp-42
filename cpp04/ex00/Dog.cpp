#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog & src )
{
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
	std::cout << "Bau bau!!" << std::endl;
}


/* ************************************************************************** */