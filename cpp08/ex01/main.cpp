# include <iostream>
# include "Span.hpp"
# include <vector>
# include <cstdlib>
# include <ctime>

void test1() {
	std::cout << "Subject test" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test2() {
	std::cout << "Testing exceptions" << std::endl;

	try {
		Span sp(0);
		sp.addNumber(42);
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp(1);
		sp.addNumber(42);
		sp.addNumber(43);
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp(2);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void test3(unsigned int n_elm, int max_elm) {
	std::cout << "Testing with " << n_elm << " elements" << std::endl;
	Span sp = Span(n_elm);
	// use iter range addNumber
	int min_elm = max_elm / 10;
	std::vector<int> v;
	for (unsigned i = 0; i < n_elm; ++i) {
		v.push_back((rand() + min_elm) % max_elm);
	}
	sp.addNumber(v.begin(), v.end());
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

int main(void) {
	srand(time(NULL));
	test1();
	test2();
	test3(1000, 10000000);
	test3(10000, 10000000);
	test3(100000, 10000000);
	return (0);
}