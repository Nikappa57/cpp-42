#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal & AAnimal::operator=( AAnimal const & rhs ) {
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

std::ostream & operator<<( std::ostream & o, AAnimal const & i ) {
	o << i.getType();
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &	AAnimal::getType(void) const {
	return this->type;
}

/* ************************************************************************** */