#include "Fixed.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	// n = raw / 2^f_bits = raw >> f_bits
	this->value = value << Fixed::f_bits;
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	// n = raw / 2^f_bits = raw / (1 << f_bits)
	// roundf is used to round the value to the nearest integer value
	// and not just truncate the decimal part
	this->value = roundf(value * (1 << Fixed::f_bits));
}


Fixed::Fixed( const Fixed & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->value = rhs.getRawBits();
	}
	return *this;

}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const {
	// (1 << Fixed::f_bits) == 2^f_bits => this->value / 2^f_bits
	return static_cast<float>(this->value) / (1 << Fixed::f_bits);
}

int Fixed::toInt(void) const {
	// this->value / 2^f_bits
	return this->value >> Fixed::f_bits;
}

/* ************************************************************************** */