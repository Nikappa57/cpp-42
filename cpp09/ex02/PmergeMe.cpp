#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR --------------------------------
*/

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91?source=post_page-----e6ad43288d4b---------------------------------------

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe( const PmergeMe & src ) { *this = src; }

PmergeMe::~PmergeMe() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs ) { (void) rhs; return *this; }

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	(void)i;
	o << "PmergeMe!";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/********** VECTOR **********/


// assume nbrs is a vector of unsigned integers with no duplicates
std::vector<unsigned> PmergeMe::sort(const std::vector<unsigned> & nbrs) {
	int n = nbrs.size();
	
	if (DEBUG) {
		std::cout << "-----" << std::endl << "Input: ";
		printContainer(nbrs);
	}
	
	// base case
	if (n <= 1)
		return nbrs;

	/* 1) Pairing */
	std::vector<unsigned> big;
	std::vector<unsigned> small;

	if (DEBUG) std::cout << "Pairing..." << std::endl;

	// make sorted pairs (skip last if nbr is odd)
	for (int i = 0; i + 1 < n; i += 2) {
		if (nbrs[i] < nbrs[i + 1]) {
			big.push_back(nbrs[i + 1]);
			small.push_back(nbrs[i]);
		} else {
			big.push_back(nbrs[i]);
			small.push_back(nbrs[i + 1]);
		}
	}

	if (DEBUG) {
		std::cout << "BIG: ";
		printContainer(big);
		std::cout << "SMALL: ";
		printContainer(small);
	}

	// recursive sort of big
	std::vector<unsigned> big_sorted = sort(big);

	// allineate small to big_sorted
	std::vector<unsigned> small_sorted;

	for (size_t i = 0; i < big_sorted.size(); ++i) {
		for (size_t j = 0; j < big.size(); ++j) {
			if (big_sorted[i] == big[j]) {
				small_sorted.push_back(small[j]);
				break;
			}
		}
	}
	// if odd, add last element to small_sorted
	if (n % 2 == 1) {
		small_sorted.push_back(nbrs[n - 1]);
	}

	if (DEBUG) {
		std::cout << "Big and small sorted: " << std::endl;
		printContainer(big_sorted);
		printContainer(small_sorted);
	}

	// 2) main chain = small[0] + big
	std::vector<unsigned> main = big_sorted;
	if (! small_sorted.empty()) {
		main.insert(main.begin(), small_sorted[0]);
	}

	if (DEBUG) {
		std::cout << "main: ";
		printContainer(main);
	}

	// 3) Insert with jacobsthal
	std::vector<unsigned> indices = getJacobsthalOrderVector(small_sorted.size());

	if (DEBUG) {
		std::cout << "Jacobsthal sequence: ";
		printContainer(indices);
	}

	for (size_t i = 0; i < indices.size(); i++) {
		unsigned idx = indices[i];
		unsigned b = small_sorted[idx];
		std::vector<unsigned>::iterator limit;

		// if it has a pair, find the a_i associated and set it as the limit in search of position
		if (idx < big_sorted.size()) {
			unsigned a = big_sorted[idx];
			limit = std::find(main.begin(), main.end(), a);
		} else {
			limit = main.end();
		}

		// binary search in main chain to add val (it must stay previous of a)
		std::vector<unsigned>::iterator pos = std::lower_bound(main.begin(), limit, b);
		main.insert(pos, b);
	}

	if (DEBUG) {
		std::cout << "Main after insert: ";
		printContainer(main);
	}

	return main;
}

// https://en.wikipedia.org/wiki/Jacobsthal_number
std::vector<unsigned> PmergeMe::getJacobsthalOrderVector(size_t size) {

	// result: list of indices to insert in the main chain
	std::vector<unsigned> indices;

	// element 1 is already in main chain, we dont need to inset it
	if (size <= 1) return indices;

	std::vector<unsigned> jacob;
	
	// base cases
	jacob.push_back(1); // J_2 = 1
	jacob.push_back(3); // J_3 = 3

	while (jacob.back() < size) {
		jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);
	}

	unsigned last_inserted = 1;

	for (size_t i = 1; i < jacob.size(); ++i) {
		unsigned current_jacob = jacob[i];
		
		if (current_jacob > size) {
			current_jacob = size;
		}

		for (unsigned j = current_jacob; j > last_inserted; --j) {
			indices.push_back(j - 1);
		}
		last_inserted = current_jacob;
	}

	return indices;
}



/********** DEQUE **********/


// assume nbrs is a list of unsigned integers with no duplicates
std::deque<unsigned> PmergeMe::sort(const std::deque<unsigned> & nbrs) {
	int n = nbrs.size();

	if (DEBUG) {
		std::cout << "-----" << std::endl << "Input: ";
		printContainer(nbrs);
	}
	
	// base case
	if (n <= 1)
		return nbrs;

	/* 1) Pairing */
	std::deque<unsigned> big;
	std::deque<unsigned> small;

	if (DEBUG) std::cout << "Pairing..." << std::endl;

	// make sorted pairs (skip last if nbr is odd)
	for (int i = 0; i + 1 < n; i += 2) {
		if (nbrs[i] < nbrs[i + 1]) {
			big.push_back(nbrs[i + 1]);
			small.push_back(nbrs[i]);
		} else {
			big.push_back(nbrs[i]);
			small.push_back(nbrs[i + 1]);
		}
	}

	if (DEBUG) {
		std::cout << "BIG: ";
		printContainer(big);
		std::cout << "SMALL: ";
		printContainer(small);
	}

	// recursive sort of big
	std::deque<unsigned> big_sorted = sort(big);

	// allineate small to big_sorted
	std::deque<unsigned> small_sorted;

	for (size_t i = 0; i < big_sorted.size(); ++i) {
		for (size_t j = 0; j < big.size(); ++j) {
			if (big_sorted[i] == big[j]) {
				small_sorted.push_back(small[j]);
				break;
			}
		}
	}
	// if odd, add last element to small_sorted
	if (n % 2 == 1) {
		small_sorted.push_back(nbrs[n - 1]);
	}

	if (DEBUG) {
		std::cout << "Big and small sorted: " << std::endl;
		printContainer(big_sorted);
		printContainer(small_sorted);
	}

	// 2) main chain = small[0] + big
	std::deque<unsigned> main = big_sorted;
	if (! small_sorted.empty()) {
		main.insert(main.begin(), small_sorted[0]);
	}

	if (DEBUG) {
		std::cout << "main: ";
		printContainer(main);
	}

	// 3) Insert with jacobsthal
	std::deque<unsigned> indices = getJacobsthalOrderDeque(small_sorted.size());

	if (DEBUG) {
		std::cout << "Jacobsthal sequence: ";
		printContainer(indices);
	}

	for (size_t i = 0; i < indices.size(); i++) {
		unsigned idx = indices[i];
		unsigned b = small_sorted[idx];
		std::deque<unsigned>::iterator limit;

		// if it has a pair, find the a_i associated and set it as the limit in search of position
		if (idx < big_sorted.size()) {
			unsigned a = big_sorted[idx];
			limit = std::find(main.begin(), main.end(), a);
		} else {
			limit = main.end();
		}

		// binary search in main chain to add val (it must stay previous of a)
		std::deque<unsigned>::iterator pos = std::lower_bound(main.begin(), limit, b);
		main.insert(pos, b);
	}

	if (DEBUG) {
		std::cout << "Main after insert: ";
		printContainer(main);
	}

	return main;
}

// https://en.wikipedia.org/wiki/Jacobsthal_number
std::deque<unsigned> PmergeMe::getJacobsthalOrderDeque(size_t size) {

	// result: list of indices to insert in the main chain
	std::deque<unsigned> indices;

	// element 1 is already in main chain, we dont need to inset it
	if (size <= 1) return indices;

	std::deque<unsigned> jacob;
	
	// base cases
	jacob.push_back(1); // J_2 = 1
	jacob.push_back(3); // J_3 = 3

	while (jacob.back() < size) {
		jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);
	}

	unsigned last_inserted = 1;

	for (size_t i = 1; i < jacob.size(); ++i) {
		unsigned current_jacob = jacob[i];
		
		if (current_jacob > size) {
			current_jacob = size;
		}

		for (unsigned j = current_jacob; j > last_inserted; --j) {
			indices.push_back(j - 1);
		}
		last_inserted = current_jacob;
	}

	return indices;
}


/* ************************************************************************** */