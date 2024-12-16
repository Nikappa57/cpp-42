#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat();
		~Cat();

		void	makeSound(void) const;
};

#endif /* ************************************************************* DOG_H */