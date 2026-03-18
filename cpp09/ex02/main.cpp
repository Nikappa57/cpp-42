#include <ctime>
#include <iomanip>

#include "PmergeMe.hpp"


/*
Tests:

./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

./PmergeMe "-1" "2"
Error
*/

// TODO: gestire numeri negativi e duplicati

int main(int argc, char **argv) {
	int						n;
	PmergeMe				pm;
	clock_t					start;

	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		if (DEBUG) std::cerr << "INVALID INPUT" << std::endl;
		return (1);
	}

	// vector
	start = clock();

	std::vector<unsigned> v;

	for (int i = 1; i < argc; ++i) {
		if (! (std::istringstream(argv[i]) >> n) || n < 0) {
			std::cerr << "Error" << std::endl;
			if (DEBUG) std::cerr << "INVALID INPUT NBR: " << n << std::endl;
			return (1);
		}
		if (std::find(v.begin(), v.end(), n) != v.end()) {
			std::cerr << "Error" << std::endl;
			if (DEBUG) std::cerr << "DUPLICATE FOUND: " << n << std::endl;
			return (1);
		}

		v.push_back(n);
	}

	std::vector<unsigned> vec_res = pm.sort(v);
	double time_vec = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;

	// deque
	start = clock();

	std::deque<unsigned>	d;

	for (int i = 1; i < argc; ++i) {
		if (! (std::istringstream(argv[i]) >> n) || n < 0) {
			std::cerr << "Error" << std::endl;
			if (DEBUG) std::cerr << "INVALID INPUT NBR: " << n << std::endl;
			return (1);
		}
		if (std::find(d.begin(), d.end(), n) != d.end()) {
			std::cerr << "Error" << std::endl;
			if (DEBUG) std::cerr << "DUPLICATE FOUND: " << n << std::endl;
			return (1);
		}
		d.push_back(n);
	}

	std::deque<unsigned> deq_res = pm.sort(d);
	double time_deq = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Before:\t";
	printContainer(v);
	std::cout << "After:\t";
	printContainer(vec_res);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of\t" << argc - 1 << " elements with std::vector :\t" << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of\t" << argc - 1 << " elements with std::deque :\t" << time_deq << " us" << std::endl;

	return (0);
}