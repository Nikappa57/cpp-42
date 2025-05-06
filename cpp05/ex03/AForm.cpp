#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// AForm::AForm()
// {
// }

AForm::AForm(const std::string name,
	const std::string target,
	unsigned int signGradeRequired,
	unsigned int execGradeRequired)
	:	_name(name),
		_target(target),
		_signed(false),
		_signGradeRequired(signGradeRequired),
		_execGradeRequired(execGradeRequired) {

	if (signGradeRequired < Bureaucrat::upperGradeLimit
		|| execGradeRequired < Bureaucrat::upperGradeLimit)
		throw AForm::GradeTooHighException();

	if (signGradeRequired > Bureaucrat::lowerGradeLimit
		|| execGradeRequired > Bureaucrat::lowerGradeLimit)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm & src )
	:	_name(src.getName()),
		_signed(src.getSigned()),
		_signGradeRequired(src.getSignGradeRequired()),
		_execGradeRequired(src.getExecGradeRequired())
{ }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// AForm &				AForm::operator=( AForm const & rhs )
// {
// 	return *this;
// }

std::ostream & operator<<( std::ostream & o, AForm const & i ) {
	o << "AForm '" << i.getName() << "' target: '" << i.getTarget()
		<< "' is " << (i.getSigned() ? "signed" : "not signed")
		<< ", sign grade required: " << i.getSignGradeRequired()
		<< ", exec grade required: " << i.getExecGradeRequired() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// private

void AForm::_checkExecRequirements(const Bureaucrat & executor) const {
	if (executor.getGrade() > _execGradeRequired)
		throw AForm::GradeTooLowException();
	if (! _signed)
		throw AForm::SignRequiredException();
}

// public

void AForm::beSign(const Bureaucrat & b) {
	if (b.getGrade() > _signGradeRequired)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat & executor) const {
	_checkExecRequirements(executor);
	_doExecute();	// Implemented by derived classes
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName() const {
	return _name;
}

std::string AForm::getTarget() const {
	return _target;
}

bool AForm::getSigned() const {
	return _signed;
}

unsigned int AForm::getSignGradeRequired() const {
	return _signGradeRequired;
}

unsigned int AForm::getExecGradeRequired() const {
	return _execGradeRequired;
}


/* ************************************************************************** */