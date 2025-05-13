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
** ------------------------------- OPERATORS --------------------------------
*/


/*
 *	Fixed point operation
 *	The essence of fixed-point arithmetic is to use integer arithmetic to simulate
 *	floating-point arithmetic.
 */

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->value + other.getRawBits());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->value - other.getRawBits());
}

Fixed Fixed::operator*(const Fixed &other) const {
	// v = n * 2^f_bits
	// n = n1 * n2
	// n1 = v1 / 2^f_bits
	// n2 = v2 / 2^f_bits
	// v = n * 2^f_bits = n1 * n2 * 2^f_bits
	//   = (v1 / 2^f_bits) * (v2 / 2^f_bits) * 2^f_bits = v1 * v2 / 2^f_bits
	//   = v1 * v2 >> f_bits
	// note that all the values are integers

	Fixed result;
	result.setRawBits(((this->value * other.getRawBits()) >> Fixed::f_bits));
	return result;

}

Fixed Fixed::operator/(const Fixed &other) const {
	// v = n * 2^f_bits
	// n = n1 / n2
	// n1 = v1 / 2^f_bits
	// n2 = v2 / 2^f_bits
	// v = n * 2^f_bits = n1 / n2 * 2^f_bits
	//   = (v1 / 2^f_bits) / (v2 / 2^f_bits) * 2^f_bits = v1 / v2 * 2^f_bits
	//   = v1 / v2 << f_bits
	// note that all the values are integers

	Fixed result;
	result.setRawBits((this->value << Fixed::f_bits) / other.getRawBits());
	return result;
}

/* increment/decrement operators */

// post increment
Fixed Fixed::operator++(int) {
	Fixed temp(*this); // save the current value
	operator++();
	return temp; // return the saved value
}

// pre increment
Fixed &Fixed::operator++(void) {
	this->value++;
	return *this;
}

// post decrement
Fixed Fixed::operator--(int) {
	Fixed temp(*this); // save the current value
	operator--();
	return temp; // return the saved value
}

// pre decrement
Fixed &Fixed::operator--(void) {
	this->value--;
	return *this;
}

/* comparison operators */

bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.getRawBits();
}

/* 
 * Min Max
 * one for non-const that returns a reference to the smallest of the two
 * and one for const that returns a (const) reference to the smallest of the two
 * and the same for the biggest of the two.
 * 
 * Note that we don't directly compare the raw values, but we use the comparison operators
 * to avoid redefining the comparison rules between the two objects.
 */

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
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