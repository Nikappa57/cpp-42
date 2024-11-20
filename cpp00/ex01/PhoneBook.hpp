#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# define CONTACTS_LEN 8
# define COLUMN_MAX_LEN 10

enum Command {
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

class PhoneBook {

	public:

		PhoneBook();
		~PhoneBook();

		void		search(void) const;
		void		add(void);

	private:

		static int	_contacts_i;
		Contact 	_contacts[CONTACTS_LEN];

		void		_printContactsList(void) const;
		Contact		_getContact(int index) const;
		void		_addNewContact(Contact contact);
		int			_readValidIndex(void) const;
};

void	print_home(void);
Command	readCommand(void);

#endif