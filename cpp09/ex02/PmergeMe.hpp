#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>
# include <sstream>

# define DEBUG 0

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		std::vector<unsigned> sort(const std::vector<unsigned> & nbrs);
		std::deque<unsigned> sort(const std::deque<unsigned> & nbrs);

	private:
		std::vector<unsigned> getJacobsthalOrderVector(size_t size);
		std::deque<unsigned> getJacobsthalOrderDeque(size_t size);
};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

// utils

template<typename T>
void printContainer(const T &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i];
		if (i + 1 < v.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

#endif /* ******************************************************** PMERGEME_H */