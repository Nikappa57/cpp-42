#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;

	print_home();
	while (true)
	{
		switch (readCommand())
		{
			case ADD:
				phoneBook.add();
				break;
			case SEARCH:
				phoneBook.search();
				break;
			case EXIT:
				return 0;
			case INVALID:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	}
}
