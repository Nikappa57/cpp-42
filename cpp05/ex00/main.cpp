# include "Bureaucrat.hpp"

inline int fail(void) {
	std::cerr << "\033[31mFAILED!\033[0m" << std::endl; // Print in red
	return 1;
}

# define CHECK(x, y) if (x != y) { return fail(); }

int main(void) {
	std::cout << "--- Bureaucrat ---" << std::endl;

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

	return 0;
}