#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// ShrubberyCreationForm::ShrubberyCreationForm()
// {
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
	:	AForm("Shrubbery Creation", target, 145, 137)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src)
	: AForm(src)
{ }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() { }

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::_doExecute() const {
	std::ofstream file;
	std::string filename = getTarget() + "_shrubbery";

	file.open(filename.c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileOpenException();

	// ASCII trees
	file << ASCII_ART;

	file.close();
}

/* ************************************************************************** */