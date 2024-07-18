#include "Contact.hpp"

Contact::Contact()
{
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNbr = "";
	_darkestSecret = "";
}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNbr() const { return _phoneNbr; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void Contact::createFromInput(void)
{
	_firstName = validInput("First name: ");
	_lastName = validInput("Last name: ");
	_nickname = validInput("Nickname: ");
	_phoneNbr = validInput("Phone number: ");
	_darkestSecret = validInput("Darkest secret: ");
}

void Contact::printDetails(void)
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNbr << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

std::string	validInput(std::string prompt)
{
	std::string input;

	input = "";
	while (input.empty())
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
	}
	return input;
}