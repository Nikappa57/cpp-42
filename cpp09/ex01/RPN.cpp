#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR  --------------------------------
*/

RPN::State const RPN::_acceptingState = OP;

const transFn RPN::_tf[6] = {
	&RPN::_init_state,
	&RPN::_n_state,
	&RPN::_s_state,
	&RPN::_op_state
};

RPN::RPN() { }

RPN::RPN( const RPN & src ) { *this = src; }

RPN::~RPN() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		// Copy the contents of rhs to this object
		this->_state = rhs._state;
		this->_stack = rhs._stack;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	(void)i;
	o << "RPN Calculator" << std::endl;
	return o;
}

std::ostream &			operator<<( std::ostream & o, RPN::State const & i )
{
	switch (i) {
		case RPN::I: o << "Initial"; break;
		case RPN::N: o << "Number"; break;
		case RPN::S: o << "Space"; break;
		case RPN::OP: o << "Operator"; break;
		default: o << "Unknown";
	}
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int RPN::calculate(const std::string & expression) {
	_state = I;
	_stack = std::stack<int>();
	for (std::size_t i = 0; i < expression.size(); ++i) {
		char c = expression[i];
		if (DEBUG) std::cout << "STATE: " << _state << ", char: '" << c << "'" << std::endl;
		(this->*_tf[_state])(c);
		if (DEBUG) std::cout << "Updated STATE: " << _state << ", stack size: " << _stack.size() << std::endl;
		if (DEBUG) std::cout << "---------------" << std::endl;
	}
	if (_state != _acceptingState)
		throw std::runtime_error("Error: Invalid expression.");
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression, stack size is not 1.");
	return _stack.top();
}

void RPN::_init_state(char c) {
	if (isdigit(c)) {
		_state = N;
		_stack.push(c - '0');
	} else {
		throw std::runtime_error("Error: not stating with a number.");
	}
}

void RPN::_n_state(char c) {
	if (c == ' ')
		_state = S;
	else
		throw std::runtime_error("Error: expected space after second number.");
}

void RPN::_s_state(char c) {
	int nbr1;
	int nbr2;

	// digit
	if (isdigit(c)) {
		_state = N;
		_stack.push(c - '0');
		return ;
	}

	// operator
	if (_stack.size() < 2)
		throw std::runtime_error("Error: not enough numbers in stack for operation.");
	if (!(c == '+' || c == '-' || c == '*' || c == '/'))
		throw std::runtime_error("Error: invalid operator.");
	_state = OP;
	nbr2 = _stack.top();
	_stack.pop();
	nbr1 = _stack.top();
	_stack.pop();
	if (c == '+')
		_stack.push(nbr1 + nbr2);
	else if (c == '-')
		_stack.push(nbr1 - nbr2);
	else if (c == '*')
		_stack.push(nbr1 * nbr2);
	else if (c == '/') {
		if (nbr2 == 0)
			throw std::runtime_error("Error: division by zero.");
		_stack.push(nbr1 / nbr2);
	}
}

void RPN::_op_state(char c) {
	if (c == ' ')
		_state = S;
	else
		throw std::runtime_error("Error: expected space after operator.");
}

/* ************************************************************************** */