# include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		std::cout << rpn.calculate(argv[1]) << std::endl;
	} catch (const std::runtime_error &e) {
		if (DEBUG) 
			std::cerr << e.what() << std::endl;
		else
			std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}

/*
test:

8 9 * 9 - 9 - 9 - 4 - 1 +
= 42

7 7 * 7 -
= 42

1 2 * 2 / 2 * 2 4 - +
= 0

(1 + 1)
error

8 2 4 1 9 3 / + - * +
= 8

1 - 2 3 + 5 +
error
*/