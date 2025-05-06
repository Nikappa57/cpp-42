#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:

		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();

	protected:

		virtual void _doExecute() const;

	private:

		RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		static bool _seeded;

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */