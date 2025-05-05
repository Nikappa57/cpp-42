#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	public:

		Form(const std::string name,
			unsigned int signGradeRequired,
			unsigned int execGradeRequired);
		Form(const Form & src);
		~Form();

		/* methods */

		void			beSign(const Bureaucrat & b);

		/* getters*/

		std::string		getName() const;
		bool			getSigned() const;
		unsigned int	getSignGradeRequired() const;
		unsigned int	getExecGradeRequired() const;

		/* Exception classes */

		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw() {
					return "Grade of the bureaucrat is too low!";
				}
		};

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw() {
					return "Grade of the bureaucrat is too high!";
				}
		};

	private:

		Form(); // default constructor is not allowed
		Form & operator=( Form const & rhs ); // no assignment operator because name is const

		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGradeRequired;
		const unsigned int	_execGradeRequired;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */