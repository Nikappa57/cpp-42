#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog();
		~Dog();

		void	makeSound(void) const;
};

#endif /* ************************************************************* DOG_H */