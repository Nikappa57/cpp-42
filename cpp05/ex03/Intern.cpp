# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR --------------------------------
*/

Intern::Intern() { }

Intern::Intern( const Intern & src ) { *this = src; }

Intern::~Intern() { }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs ) { 
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Intern";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

// helpers

AForm * Intern::_createShrubbery(const std::string & target) const
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::_createRobotomy(const std::string & target) const
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::_createPardon(const std::string & target) const
{
	return new PresidentialPardonForm(target);
}

// Array of form entries
const Intern::FormEntry Intern::_formEntries[3] = {
	{"shrubbery creation", &Intern::_createShrubbery},
	{"robotomy request", &Intern::_createRobotomy},
	{"presidential pardon", &Intern::_createPardon}
};

// Factory method to create a form
AForm * Intern::makeForm(const std::string & formName, const std::string & target) const {
	for (int i = 0; i < FORM_N; i++) {
		if (formName == _formEntries[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*_formEntries[i].creator)(target);
		}
	}
	std::cerr << "Error! Form " << formName << " not found!" << std::endl;
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */