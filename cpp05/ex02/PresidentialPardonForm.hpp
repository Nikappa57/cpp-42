#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	public:

		PresidentialPardonForm(const std::string & target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

	protected:

		virtual void _doExecute() const;

	private:

		PresidentialPardonForm();
		PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */