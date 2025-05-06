# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"


inline int fail(void) {
	std::cerr << "FAILED!" << std::endl;
	return 1;
}

# define CHECK(x, y) \
	if (x != y) { \
		do { \
			std::cout << "CHECK failed: " << #x << " != " << #y << std::endl; \
			return fail(); \
		} while(0); \
	}

int main(void) {
	std::cout << "--- Bureaucrat ---" << std::endl;

	/*--- Bureaucrat ---*/

	// TEST 1: Basics
	{
		std::cout << "1) simple test: create a valid bureaucrat, "
			<< "and use all basic methods" << std::endl;

		try {
			unsigned int	grade_ = 50; // a valid grade, not equal to upper or lower limits
			std::string		name_ = "Marius";
			Bureaucrat bureaucrat(name_, grade_);
			std::cout << bureaucrat << std::endl;

			std::cout << "increment grade" << std::endl;
			bureaucrat.incrementGrade();
			std::cout << "grade: " << bureaucrat.getGrade() << std::endl;
			CHECK(bureaucrat.getGrade(), grade_ - 1);

			std::cout << "decrement grade" << std::endl;
			bureaucrat.decrementGrade();
			std::cout << "grade: " << bureaucrat.getGrade() << std::endl;
			CHECK(bureaucrat.getGrade(), grade_);

			std::cout << "Name is: " << bureaucrat.getName() << std::endl;
			CHECK(bureaucrat.getName(), name_);
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}

	// TEST 2: Constructor exceptions
	{
		std::cout << "2.1) create a bureaucrat with invalid grade (too high)" << std::endl;
		try {
			Bureaucrat bureaucrat("Marius", Bureaucrat::upperGradeLimit - 1);	// should throw
			std::cout << bureaucrat << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}
		std::cout << "2.2) create a bureaucrat with invalid grade (too low)" << std::endl;
		try {
			Bureaucrat bureaucrat("Marius", Bureaucrat::lowerGradeLimit + 1);	// should throw
			std::cout << bureaucrat << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}
	}

	// TEST 3: Increment/Decrement exceptions
	{
		std::cout << "3.1) Increment grade to the maximum" << std::endl;
		try {
			Bureaucrat bureaucrat("Marius", Bureaucrat::upperGradeLimit);
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();	// should throw
			std::cout << bureaucrat << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}
		std::cout << "3.2) Decrement grade to the minimum" << std::endl;
		try {
			Bureaucrat bureaucrat("Marius", Bureaucrat::lowerGradeLimit);
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();	// should throw
			std::cout << bureaucrat << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}
	}

	/*--- FORM ---*/

	std::cout << "--- FORM ---" << std::endl;

	std::cout << "--- SHRUBBERY FORM ---" << std::endl;
	// TEST 1: Basics
	{
		std::cout << "1) Create a ShrubberyCreationForm and execute it" << std::endl;

		try {
			ShrubberyCreationForm form("home");
			std::cout << form << std::endl;

			// Check initial state
			CHECK(form.getName(), "Shrubbery Creation");
			CHECK(form.getSigned(), false);
			CHECK(form.getSignGradeRequired(), 145);
			CHECK(form.getExecGradeRequired(), 137);

			// Sign the form
			Bureaucrat admin("Marius", Bureaucrat::upperGradeLimit);
			admin.signForm(form);
			CHECK(form.getSigned(), true);

			// exec the form
			admin.executeForm(form);

			std::cout << "Shrubbery created successfully!" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 2: Execution without signing
	{
		std::cout << "2) Attempt to execute an unsigned ShrubberyCreationForm" << std::endl;

		try {
			ShrubberyCreationForm form("home");
			Bureaucrat executor("Marius?", form.getExecGradeRequired());
			std::cout << "CHECK ERROR: ";
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 3: Signing with insufficient grade
	{
		std::cout << "3) Attempt to sign a ShrubberyCreationForm with insufficient grade" << std::endl;

		try {
			ShrubberyCreationForm form("home");
			Bureaucrat bureaucrat("Marius", form.getSignGradeRequired() + 1); // Grade too low to sign
			std::cout << "CHECK ERROR: ";
			bureaucrat.signForm(form); // Should print error message without throwing
			CHECK(form.getSigned(), false);
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 4: Execution with insufficient grade
	{
		std::cout << "4) Attempt to execute a ShrubberyCreationForm with insufficient grade" << std::endl;

		try {
			ShrubberyCreationForm form("home");
			Bureaucrat signer("Marius", form.getSignGradeRequired());
			Bureaucrat executor("Valerius", form.getExecGradeRequired() + 1); // Grade too low to execute

			signer.signForm(form);
			std::cout << "CHECK ERROR: ";
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cerr << "SUCCESS!" << std::endl;
	}


	std::cout << "--- RobotomyRequestForm FORM ---" << std::endl;
	// TEST 1: Basics
	{
		std::cout << "1) Create a RobotomyRequestForm and execute it" << std::endl;

		try {
			RobotomyRequestForm form("home");
			std::cout << form << std::endl;

			// Check initial state
			CHECK(form.getName(), "Robotomy Request");
			CHECK(form.getSigned(), false);
			CHECK(form.getSignGradeRequired(), 72);
			CHECK(form.getExecGradeRequired(), 45);

			// Sign the form
			Bureaucrat admin("Marius", Bureaucrat::upperGradeLimit);
			admin.signForm(form);
			CHECK(form.getSigned(), true);

			// exec the form
			admin.executeForm(form);

			std::cout << "Shrubbery created successfully!" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 2: Execution without signing
	{
		std::cout << "2) Attempt to execute an unsigned RobotomyRequestForm" << std::endl;

		try {
			RobotomyRequestForm form("home");
			Bureaucrat executor("Marius?", form.getExecGradeRequired());
			std::cout << "CHECK ERROR: ";
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
	}
	// TEST 3: Signing with insufficient grade
	{
		std::cout << "3) Attempt to sign a RobotomyRequestForm with insufficient grade" << std::endl;

		try {
			RobotomyRequestForm form("home");
			Bureaucrat bureaucrat("Marius", form.getSignGradeRequired() + 1); // Grade too low to sign
			std::cout << "CHECK ERROR: ";
			bureaucrat.signForm(form); // Should print error message without throwing
			CHECK(form.getSigned(), false);
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 4: Execution with insufficient grade
	{
		std::cout << "4) Attempt to execute a RobotomyRequestForm with insufficient grade" << std::endl;

		try {
			RobotomyRequestForm form("home");
			Bureaucrat signer("Marius", form.getSignGradeRequired());
			Bureaucrat executor("Valerius", form.getExecGradeRequired() + 1); // Grade too low to execute

			signer.signForm(form);
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}

	std::cout << "--- PresidentialPardonForm FORM ---" << std::endl;
	// TEST 1: Basics
	{
		std::cout << "1) Create a PresidentialPardonForm and execute it" << std::endl;

		try {
			PresidentialPardonForm form("home");
			std::cout << form << std::endl;

			// Check initial state
			CHECK(form.getName(), "Presidential Pardon");
			CHECK(form.getSigned(), false);
			CHECK(form.getSignGradeRequired(), 25);
			CHECK(form.getExecGradeRequired(), 5);

			// Sign the form
			Bureaucrat admin("Marius", Bureaucrat::upperGradeLimit);
			admin.signForm(form);
			CHECK(form.getSigned(), true);

			// exec the form
			admin.executeForm(form);

			std::cout << "Shrubbery created successfully!" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 2: Execution without signing
	{
		std::cout << "2) Attempt to execute an unsigned PresidentialPardonForm" << std::endl;

		try {
			PresidentialPardonForm form("home");
			Bureaucrat executor("Marius?", form.getExecGradeRequired());
			std::cout << "CHECK ERROR: ";
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 3: Signing with insufficient grade
	{
		std::cout << "3) Attempt to sign a PresidentialPardonForm with insufficient grade" << std::endl;

		try {
			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("Marius", form.getSignGradeRequired() + 1); // Grade too low to sign
			std::cout << "CHECK ERROR: ";
			bureaucrat.signForm(form); // Should print error message without throwing
			CHECK(form.getSigned(), false);
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	// TEST 4: Execution with insufficient grade
	{
		std::cout << "4) Attempt to execute a PresidentialPardonForm with insufficient grade" << std::endl;

		try {
			PresidentialPardonForm form("home");
			Bureaucrat signer("Marius", form.getSignGradeRequired());
			Bureaucrat executor("Valerius", form.getExecGradeRequired() + 1); // Grade too low to execute

			signer.signForm(form);
			std::cout << "CHECK ERROR: ";
			executor.executeForm(form); // Should print error message without throwing
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}

	std::cout << "All tests passed!" << std::endl;
	return 0;
}