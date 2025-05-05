#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;

	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( const Cat & src ) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat & Cat::operator=( Cat const & rhs ) {
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

void Cat::makeSound(void) const {
	std::cout << "Miao..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Cat::getBrain(void) const {
	return this->brain;
}



/* ************************************************************************** */