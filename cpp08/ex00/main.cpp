#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <deque>
#include <stack>
#include <vector>

# define N 10

int main(void) {
	// some containers to test
	std::list<int> list;
	std::deque<int> deq;
	std::vector<int> vec;
	std::vector<int> empty_vec; // just for test
	
	// fill the containers
	for (int i = 0; i < N; i++) {
		list.push_back(i);
		deq.push_back(i);
		vec.push_back(i);
	}

	// use easyfind
	for (int i = 0; i < 2 * N; i += (N / 5)) {
		if (easyfind(list, i))
			std::cout << "Found " << i << " in list" << std::endl;
		else
			std::cout << "Did not find " << i << " in list" << std::endl;

		if (easyfind(deq, i))
			std::cout << "Found " << i << " in deque" << std::endl;
		else
			std::cout << "Did not find " << i << " in deque" << std::endl;

		if (easyfind(vec, i))
			std::cout << "Found " << i << " in vector" << std::endl;
		else
			std::cout << "Did not find " << i << " in vector" << std::endl;

		if (easyfind(empty_vec, i))
			std::cout << "Found " << i << " in empty vector!!" << std::endl;
		else
			std::cout << "Did not find " << i << " in empty vector" << std::endl;
	}

	// test with an empty container


}