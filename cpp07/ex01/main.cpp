# include <iostream>
# include "iter.hpp"

# define N 10


void print_val_int(int &elm) {
	std::cout << elm << " ";
}

void increment_int(int &elm) {
	elm++;
}

int main( void ) {
	int arr_int[N] = {0};

	for (int i = 0; i < N; i++)
		arr_int[i] = i;

	// print arr with iter
	std::cout << "arr:" << std::endl;
	iter(arr_int, N, print_val_int);
	std::cout << std::endl;

	// note: implicit funtion-to-pointer conversion
	// print_val_int -> &print_val_int
	// https://en.cppreference.com/w/cpp/language/implicit_conversion

	// increment arr elems with iter
	iter(arr_int, N, increment_int);

	// print arr with iter
	std::cout << "arr after increment:" << std::endl;
	iter(arr_int, N, print_val_int);
	std::cout << std::endl;

	/*** test with instantiated function template **/

	float arr_float[N] = {0.0f};
	for (int i = 0; i < N; i++)
		arr_float[i] = static_cast<float>(i) + 0.5f;

	// print arr with iter
	std::cout << "arr_float:" << std::endl;
	iter(arr_float, N, print_val<float>);
	std::cout << std::endl;

	// increment arr elems with iter
	iter(arr_float, N, increment<float>);

	// print arr with iter
	std::cout << "arr_float after increment:" << std::endl;
	iter(arr_float, N, print_val<float>);
	std::cout << std::endl;

	return 0;
}