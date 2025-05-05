#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// To avoid magic numbers, the upper and lower grade limits are defined as static constants
// Note that grade 1 is the highest and 150 the lowest

const unsigned int Bureaucrat::upperGradeLimit = 1;
const unsigned int Bureaucrat::lowerGradeLimit = 150;

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
	: _name(name), _grade(grade)
{
	if (grade < upperGradeLimit)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > lowerGradeLimit)
		throw Bureaucrat::GradeTooLowException();
}

// no default constructor is allowed, must construct with name and grade
// Bureaucrat::Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src.getName()), _grade(src.getGrade())
{ }	// made in this way beacause name is const and the = operator is not allowed

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() { }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// no = operator because the const name member cannot be changed
// Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs ){ }

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i) {
	// <name>, bureaucrat grade <grade>
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade() {
	if (_grade <= upperGradeLimit)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= lowerGradeLimit)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

/* ************************************************************************** */