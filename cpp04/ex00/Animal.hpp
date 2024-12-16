#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		~Animal();

		Animal &			operator=( Animal const & rhs );

		void				makeSound(void) const;
		const std::string &	getType(void) const;

	protected:
		std::string	type;
};

std::ostream &				operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */