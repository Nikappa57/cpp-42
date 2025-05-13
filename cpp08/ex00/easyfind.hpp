#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

// see std::find https://cplusplus.com/reference/algorithm/find/

/*
*	Find an integer in a container
*	return true if found, false otherwise
*/
template <typename T>
bool easyfind(const T & int_cont, int val) {
	return (std::find(int_cont.begin(), int_cont.end(), val) != int_cont.end());
}

#endif
