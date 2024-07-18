#include "PhoneBook.hpp"

/* public */

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::readValidIndex(void)
{
	int			index;

	while (true)
	{
		std::cout << "index: " << std::flush;
		std::cin >> index;
		if (std::cin.good() && (index >= 0) && (index < _contacts_i))
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return index;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
	}
	return index;
}

void	PhoneBook::search(void)
{
	int	index;

	if (_contacts_i == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}
	printContactsList();
	index = readValidIndex();
	Contact contact = getContact(index);
	contact.printDetails();
}

void		PhoneBook::add(void)
{
	Contact	contact;

	std::cout << "Add new contact" << std::endl;
	contact.createFromInput();
	addNewContact(contact);
	std::cout << "Contact added" << std::endl;
}

/* private */

int	PhoneBook::_contacts_i = 0;

Contact	PhoneBook::getContact(int index) const
{
	return _contacts[index];
}

void	PhoneBook::addNewContact(Contact contact)
{
	_contacts[_contacts_i++ % CONTACTS_LEN] = contact;
}

static	std::string	formatContactField(std::string field)
{
	std::string	result;

	result = field;
	if (result.length() > COLUMN_MAX_LEN)										// trunc the field if it is too long
	{
		result = result.substr(0, COLUMN_MAX_LEN - 1);
		result += ".";
	}
	else
		result = std::string(COLUMN_MAX_LEN - result.length(), ' ') + result; // padding for right alignment
	return result;
}

static	std::string	formatContact(Contact contact, int index)
{
	std::string	result;

	result = std::to_string(index) + "|";
	result += formatContactField(contact.getFirstName()) + "|";
	result += formatContactField(contact.getLastName()) + "|";
	result += formatContactField(contact.getNickname());
	return result;
}

void	PhoneBook::printContactsList(void) const
{
	std::string line;

	for (int i = 0; i < _contacts_i; i++)
		std::cout << formatContact(_contacts[i], i) << std::endl;
}

/* utils */

void	print_home(void)
{
	std::cout << std::endl << std::endl;
	std::cout << "\t\tPhone Book" << std::endl << std::endl;
	std::cout << "\t\tADD - save a new contac" << std::endl;
	std::cout << "\t\tSEARCH - display contacts list" << std::endl;
	std::cout << "\t\tEXIT - exit the program" << std::endl;
}

Command	readCommand(void)
{
	std::string	command;

	std::cout << ">> " << std::flush;
	if (!getline(std::cin, command))
		return INVALID;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return INVALID;
	}
	if (command.compare("EXIT") == 0)
		return EXIT;
	if (command.compare("ADD") == 0)
		return ADD;
	if (command.compare("SEARCH") == 0)
		return SEARCH;
	return INVALID;
}
