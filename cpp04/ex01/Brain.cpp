#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain & src ) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs ) {
	if ( this != &rhs )
	{
		for (int i = 0; i < IDEAS_N; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i ) {
	o << "Brain( ";
	for (int j = 0; j < IDEAS_N; j++)
	{
		if (i.getIdea(j).empty() == false)
			o << " |" << i.getIdea(j) << "| ";
	}
	o << " )";
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &	Brain::getIdea(int i) const {
	return this->ideas[i];
}

void	Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}


/* ************************************************************************** */