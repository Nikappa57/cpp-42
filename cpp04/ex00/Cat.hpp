#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );

		void	makeSound(void) const;
};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* DOG_H */