#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 10
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// print elems
	std::cout << "Numbers:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		// print temp
		std::cout << "Temp:" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << tmp[i] << " ";
		std::cout << std::endl;

		// print test
		std::cout << "Test:" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << test[i] << " ";
		std::cout << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	std::cout << "Trying to access out of bounds" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Trying to access in bounds" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	// print elems
	std::cout << "New numbers:" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	delete [] mirror;//
	return 0;
}