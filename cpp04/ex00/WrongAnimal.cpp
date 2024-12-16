#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs ) {
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

std::ostream & operator<<( std::ostream & o, WrongAnimal const & i ) {
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound(void) const {
	std::cout << "Wrong animal sound..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &	WrongAnimal::getType(void) const {
	return this->type;
}

/* ************************************************************************** */