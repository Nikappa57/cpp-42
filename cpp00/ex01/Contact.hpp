#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{

	public:

		Contact();
		~Contact();

		void		createFromInput(void);
		void		printDetails(void);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNbr(void) const;
		std::string	getDarkestSecret(void) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNbr;
		std::string	_darkestSecret;
};

std::string	validInput(std::string prompt);

#endif