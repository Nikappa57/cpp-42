#include "Contact.hpp"

Contact::Contact(void) {
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNbr = "";
	_darkestSecret = "";
}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const { return _firstName; }
std::string Contact::getLastName(void) const { return _lastName; }
std::string Contact::getNickname(void) const { return _nickname; }
std::string Contact::getPhoneNbr(void) const { return _phoneNbr; }
std::string Contact::getDarkestSecret(void) const { return _darkestSecret; }

void Contact::createFromInput(void) {
	_firstName = validInput("First name: ");
	_lastName = validInput("Last name: ");
	_nickname = validInput("Nickname: ");
	_phoneNbr = validInput("Phone number: ");
	_darkestSecret = validInput("Darkest secret: ");
}

void Contact::printDetails(void) const {
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNbr << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

std::string validInput(std::string prompt) {
	std::string input;

	input = "";
	while (input.empty())
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, input))
			exit(1);
	}
	return input;
}