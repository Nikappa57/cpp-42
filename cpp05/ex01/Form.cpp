#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// Form::Form()
// {
// }

Form::Form(const std::string name,
	unsigned int signGradeRequired,
	unsigned int execGradeRequired)
	:	_name(name),
		_signed(false),
		_signGradeRequired(signGradeRequired),
		_execGradeRequired(execGradeRequired) {

	if (signGradeRequired < Bureaucrat::upperGradeLimit
		|| execGradeRequired < Bureaucrat::upperGradeLimit)
		throw Form::GradeTooHighException();

	if (signGradeRequired > Bureaucrat::lowerGradeLimit
		|| execGradeRequired > Bureaucrat::lowerGradeLimit)
		throw Form::GradeTooLowException();
}

Form::Form( const Form & src )
	:	_name(src.getName()),
		_signed(src.getSigned()),
		_signGradeRequired(src.getSignGradeRequired()),
		_execGradeRequired(src.getExecGradeRequired())
{ }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Form &				Form::operator=( Form const & rhs )
// {
// 	return *this;
// }

std::ostream & operator<<( std::ostream & o, Form const & i ) {
	o << "Form '" << i.getName() << "' is "
		<< (i.getSigned() ? "signed" : "not signed")
		<< ", sign grade required: " << i.getSignGradeRequired()
		<< ", exec grade required: " << i.getExecGradeRequired() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSign(const Bureaucrat & b) {
	if (b.getGrade() > _signGradeRequired)
		throw Form::GradeTooLowException();
	_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

unsigned int Form::getSignGradeRequired() const {
	return _signGradeRequired;
}

unsigned int Form::getExecGradeRequired() const {
	return _execGradeRequired;
}


/* ************************************************************************** */