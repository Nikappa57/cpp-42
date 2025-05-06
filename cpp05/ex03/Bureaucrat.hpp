#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm;

class Bureaucrat {

	public:

		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		/* getters */

		std::string		getName() const;
		unsigned int	getGrade() const;

		/* methods */
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm & form) const;
		void			executeForm(AForm const & form) const;
		// To avoid magic numbers, the upper and lower grade limits are defined as static constants

		static const unsigned int	upperGradeLimit;
		static const unsigned int	lowerGradeLimit;

		/* Exception classes */

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw() {
					return "Grade too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw() {
					return "Grade too low!";
				}
		};
	private:

		Bureaucrat();	// Must construct with name and grade
		Bureaucrat& operator=( Bureaucrat const & rhs ); // no assignment operator because name is const

		const std::string	_name;
		unsigned int		_grade;

	
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */