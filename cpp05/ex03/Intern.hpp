#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define FORM_N 3

class Intern {

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		// Factory method to create a form
		AForm * makeForm(const std::string & formName, const std::string & target) const;

	private:
		typedef AForm * (Intern::*FormCreator)(const std::string & target) const;
		struct FormEntry {
			std::string name;
			FormCreator creator;
		};
		static const FormEntry _formEntries[FORM_N];
	
		/* factory helper */
		AForm * _createShrubbery(const std::string & target) const;
		AForm * _createRobotomy(const std::string & target) const;
		AForm * _createPardon(const std::string & target) const;
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */