#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# define CONTACTS_LEN 8
# define COLUMN_MAX_LEN 10

enum Command
{
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

class PhoneBook
{

	public:

		PhoneBook();
		~PhoneBook();

		void		search(void);
		void		add(void);

	private:

		static int	_contacts_i;

		Contact 	_contacts[CONTACTS_LEN];
		void		printContactsList(void) const;
		Contact		getContact(int index) const;
		void		addNewContact(Contact contact);
		int			readValidIndex(void);
};

void	print_home(void);
Command	readCommand(void);

#endif