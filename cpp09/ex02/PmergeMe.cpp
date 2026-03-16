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

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		// TODO: finish
		this->_vInput = rhs._vInput;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	(void)i;
	o << "PmergeMe!";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static void printVector(const std::vector<unsigned> &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i];
		if (i + 1 < v.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

// assume nbrs is a vector of unsigned integers with no duplicates
std::vector<unsigned> PmergeMe::sortVector(std::vector<unsigned> nbrs) {
	int n = nbrs.size();
	
	if (DEBUG) {
		std::cout << "Input: ";
		printVector(nbrs);
	}
	
	// base case
	if (n <= 1)
		return nbrs;


	/* 1) Pairing */
	std::vector<unsigned> big; // forse da cambiare in as e bs?
	std::vector<unsigned> pend;

	if (DEBUG) std::cout << "Pairing..." << std::endl;

	// make sorted pairs
	for (int i = 0; i + 1 < n; i += 2) {
		if (nbrs[i] < nbrs[i + 1]) {
			big.push_back(nbrs[i + 1]);
			pend.push_back(nbrs[i]);
		} else {
			big.push_back(nbrs[i]);
			pend.push_back(nbrs[i + 1]);
		}
	}

	// if odd, add last element to pend
	if (n % 2 == 1)
		pend.push_back(nbrs[n - 1]);

	if (DEBUG) {
		std::cout << "Pairs: ";
		printVector(big);
		std::cout << "Pend: ";
		printVector(pend);
	}

	// recursive sort of big
	std::vector<unsigned> big_sorted = sortVector(big);

	if (DEBUG) {
		std::cout << "Big sorted: ";
		printVector(big_sorted);
	}

	/* 2) MAIN + PEND */
	std::vector<unsigned> main;
	// add b1 to main
	main.push_back(pend);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */