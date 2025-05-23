#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &			operator=( WrongAnimal const & rhs );

		void				makeSound(void) const;
		const std::string &	getType(void) const;

	protected:
		std::string	type;
};

std::ostream &				operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */