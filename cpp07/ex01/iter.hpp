#include <cstddef>
#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T * arr, const std::size_t len,
		void fun(T &)) { // syntactic sugar! equals to "void (*fun)(T &)"
	if (!arr) return ;
	for (std::size_t i = 0; i < len; i++)
		fun(arr[i]);
}

template <typename T>
void iter(const T * arr, const std::size_t len,
		void fun(const T &)) {
	if (!arr) return ;
	for (std::size_t i = 0; i < len; i++)
		fun(arr[i]);
}

// template test fun

template <typename T>
void print_val(T &elm) {
	std::cout << elm << " ";
}

template <typename T>
void increment(T &elm) {
	elm++;
}

#endif