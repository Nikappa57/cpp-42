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
	for (int i = 0; i <= N; i += (N / 5)) {
		try {
			std::cout << "Search " << i << " in list" << std::endl;
			easyfind(list, i);
			std::cout << "Found " << i << " in list" << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "Search " << i << " in deque" << std::endl;
			easyfind(deq, i);
			std::cout << "Found " << i << " in deque" << std::endl;
		} catch (const std::exception & e) {
			
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "Search " << i << " in vector" << std::endl;
			easyfind(vec, i);
			std::cout << "Found " << i << " in vector" << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "Search " << i << " in empty vector" << std::endl;
			easyfind(empty_vec, i);
			std::cout << "Found " << i << " in empty vector (!?)" << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}