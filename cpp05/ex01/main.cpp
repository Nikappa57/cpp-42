# include "Bureaucrat.hpp"
# include "Form.hpp"

inline int fail(void) {
	std::cerr << "FAILED!" << std::endl;
	return 1;
}

# define CHECK(x, y) if (x != y) { return fail(); }

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

	// TEST 4: Form Basics
	{
		std::cout << "4) simple test: create a form and use all basic methods" << std::endl;

		try {
			unsigned int	signGradeRequired = 50;
			unsigned int	execGradeRequired = 50;
			std::string		name = "Form1";
			Form form(name, signGradeRequired, execGradeRequired);
			std::cout << form << std::endl;

			// check for getters
			CHECK(form.getName(), name);
			CHECK(form.getSigned(), false);
			CHECK(form.getSignGradeRequired(), signGradeRequired);
			CHECK(form.getExecGradeRequired(), execGradeRequired);

			// check sign method
			Bureaucrat bureaucrat("Marius", signGradeRequired);
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			CHECK(form.getSigned(), true);
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}
	
	// TEST 5: Form construction exceptions
	{
		std::cout << "5.1) create a form with invalid sign grade (too high)" << std::endl;
		try {
			Form form("Form", Bureaucrat::upperGradeLimit - 1, 50);	// should throw
			std::cout << form << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}

		std::cout << "5.2) create a form with invalid sign grade (too low)" << std::endl;
		try {
			Form form("Form", Bureaucrat::lowerGradeLimit + 1, 50);	// should throw
			std::cout << form << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}

		std::cout << "5.3) create a form with invalid exec grade (too high)" << std::endl;
		try {
			Form form("Form", 50, Bureaucrat::upperGradeLimit - 1);	// should throw
			std::cout << form << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}

		std::cout << "5.4) create a form with invalid exec grade (too low)" << std::endl;
		try {
			Form form("Form", 50, Bureaucrat::lowerGradeLimit + 1);	// should throw
			std::cout << form << std::endl;
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}
	}

	// TEST 6: Form sign exceptions
	{
		std::cout << "6.1) Sign form with bureaucrat grade too low (beSign)" << std::endl;
		try {
			unsigned int	signGradeRequired = 50;
			Form form("Form", signGradeRequired, 50);
			std::cout << form << std::endl;

			Bureaucrat bureaucrat("Marius", signGradeRequired + 1);
			std::cout << bureaucrat << std::endl;

			form.beSign(bureaucrat);	// should throw
			return fail();
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cerr << "SUCCESS!" << std::endl;
		}

		std::cout << "6.2) Sign form with bureaucrat grade too low (signForm)" << std::endl;
		try {
			unsigned int	signGradeRequired = 50;
			Form form("Form", signGradeRequired, 50);
			std::cout << form << std::endl;

			Bureaucrat bureaucrat("Marius", signGradeRequired + 1);
			std::cout << bureaucrat << std::endl;

			bureaucrat.signForm(form);	// should print err message without throwing
			CHECK(form.getSigned(), false);
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return fail();
		}
		std::cout << "SUCCESS!" << std::endl;
	}


	return 0;
}