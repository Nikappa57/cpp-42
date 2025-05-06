#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{

	public:

		AForm(const std::string name,
			const std::string target,
			unsigned int signGradeRequired,
			unsigned int execGradeRequired);
		AForm(const AForm & src);
		virtual ~AForm();

		/* methods */

		void			beSign(const Bureaucrat & b);

		/*	
		**	Execute
		**	Template Method:
		**		Define the skeleton of an algorithm in an operation,
		**		deferring some steps to subclasses (Design Patterns)
		**	private execute(): check for requirements (sign, grade)
		**		and call _doExecute() to execute the specific action.
		**	protected _doExecute(): to be implemented by derived classes.
		*/
		void			execute(const Bureaucrat & executor) const;

		/* getters*/
		
		std::string		getName() const;
		std::string		getTarget() const;
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

		class SignRequiredException : public std::exception {
			public:
				const char * what() const throw() {
					return "Form is not signed!";
				}
		};
	
	protected:
		virtual void	_doExecute() const = 0;

	private:

		AForm(); // default constructor is not allowed
		AForm & operator=( AForm const & rhs ); // no assignment operator because name is const

		void				_checkExecRequirements(const Bureaucrat & b) const;

		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const unsigned int	_signGradeRequired;
		const unsigned int	_execGradeRequired;
};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */