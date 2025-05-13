# include "Span.hpp"
# include <limits>

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR--------------------------------
*/

Span::Span(unsigned int n) : _limit(n) { }

Span::Span( const Span & src ) {
	*this = src;
}

Span::~Span() { }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs ) {
	if ( this != &rhs ) {
		this->_limit = rhs._limit;
		this->_numbers = rhs._numbers;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i ) {
	(void)i;
	o << "Span";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n) {
	if (_numbers.size() >= _limit)
		throw Span::FullException();
	_numbers.insert(n);
}

int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();
	// last - first
	return (*_numbers.rbegin() - *_numbers.begin());
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();
	int min = std::numeric_limits<int>::max();
	std::multiset<int>::const_iterator itr1 = _numbers.begin();
	std::multiset<int>::const_iterator itr2 = ++_numbers.begin();
	for (; itr2 != _numbers.end(); ++itr1, ++itr2) {
		if ((min = std::min(min, *itr2 - *itr1)) == 0) break;
	}
	return min;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */