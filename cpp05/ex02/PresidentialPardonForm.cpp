#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// PresidentialPardonForm::PresidentialPardonForm()
// {
// }

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
	:	AForm("Presidential Pardon", target, 25, 5)
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src)
	: AForm(src)
{ }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() { }


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::_doExecute() const {
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */