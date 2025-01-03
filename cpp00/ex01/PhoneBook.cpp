#include "PhoneBook.hpp"

/* public */

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

int PhoneBook::_readValidIndex(void) const {
	int	index = -1;

	while (true) {
		std::cout << "index: " << std::flush;
		std::cin >> index;

		index--;
		if (std::cin.eof()) {
			std::cout << "EOF received. Exiting." << std::endl;
			exit(0);
		} if (std::cin.good() && (index >= 0) && (index < _contacts_n)) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return index;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index" << std::endl;
	}
	return index;
}

void PhoneBook::search(void) const {
	int	index;

	if (_contacts_n == 0) {
		std::cout << "No contacts available" << std::endl;
		return;
	}
	_printContactsList();
	index = _readValidIndex();
	Contact contact = _getContact(index);
	contact.printDetails();
}

void PhoneBook::add(void) {
	Contact	contact;

	std::cout << "Add new contact" << std::endl;
	contact.createFromInput();
	_addNewContact(contact);
	std::cout << "Contact added" << std::endl;
}

/* private */

int	PhoneBook::_contacts_i = 0;
int	PhoneBook::_contacts_n = 0;

Contact PhoneBook::_getContact(int index) const {
	return _contacts[index];
}

void PhoneBook::_addNewContact(Contact contact) {
	_contacts[_contacts_i] = contact;
	_contacts_i = (_contacts_i + 1) % CONTACTS_LEN;
	if (_contacts_n < CONTACTS_LEN)
		_contacts_n++;
}

static std::string formatContactField(std::string field) {
	std::string	result;

	result = field;
	if (result.length() > COLUMN_MAX_LEN) {	// trunc the field if it is too long 
		result = result.substr(0, COLUMN_MAX_LEN - 1);
		result += ".";
	}
	else
		result = std::string(COLUMN_MAX_LEN - result.length(), ' ') + result; // padding for right alignment
	return result;
}

static void printContact(Contact contact, int index) {
	std::cout << "         " << index << "|"
		<< formatContactField(contact.getFirstName()) << "|"
		<< formatContactField(contact.getLastName()) << "|"
		<< formatContactField(contact.getNickname()) << "|"<< std::endl;
}

void	PhoneBook::_printContactsList(void) const {
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < _contacts_n; i++)
		printContact(_contacts[i], i + 1);
}

/* utils */

void	print_home(void) {
	std::cout << std::endl << std::endl;
	std::cout << "\t\tPhone Book" << std::endl << std::endl;
	std::cout << "\t\tADD - save a new contact" << std::endl;
	std::cout << "\t\tSEARCH - display contacts list" << std::endl;
	std::cout << "\t\tEXIT - exit the program" << std::endl;
}

Command	readCommand(void) {
	std::string	command;

	std::cout << ">> " << std::flush;
	if (!getline(std::cin, command))
		return EXIT;
	if (command == "EXIT")
		return EXIT;
	if (command == "ADD")
		return ADD;
	if (command == "SEARCH")
		return SEARCH;
	return INVALID;
}
