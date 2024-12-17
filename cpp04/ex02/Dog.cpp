#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : AAnimal() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( const Dog & src ) : AAnimal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog & Dog::operator=( Dog const & rhs ) {
	if ( this != &rhs )
	{
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
	std::cout << "Bau bau!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Dog::getBrain(void) const {
	return this->brain;
}


/* ************************************************************************** */