#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

// see std::find https://cplusplus.com/reference/algorithm/find/

/*
*	Find an integer in a container
*	return true if found, false otherwise
*/
template <typename T>
typename T::const_iterator easyfind(const T & int_cont, int val) {
	typename T::const_iterator it = std::find(int_cont.begin(), int_cont.end(), val);
	if (it == int_cont.end())
		throw std::out_of_range("no elemen found");
	return it;
}

#endif
