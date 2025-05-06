#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

// RobotomyRequestForm::RobotomyRequestForm()
// {
// }

bool RobotomyRequestForm::_seeded = false;

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
	:	AForm("Robotomy Request", target, 72, 45)
{
	// seed for random number generation
	if (!_seeded) {
		std::srand(std::time(0));
		_seeded = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
	: AForm(src)
{ }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() { }
 


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::_doExecute() const {
	std::cout << "* drilling noises *" << std::endl;

	if ((std::rand() % 2) == 0) // 50% chance
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << getTarget() << "!" << std::endl;
}


/* ************************************************************************** */