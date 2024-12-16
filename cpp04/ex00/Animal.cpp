#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type("Generic") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal & src ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs ) {
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i ) {
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const {
	std::cout << "Animal sound..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &	Animal::getType(void) const {
	return this->type;
}

/* ************************************************************************** */