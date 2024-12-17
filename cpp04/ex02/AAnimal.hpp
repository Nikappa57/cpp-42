#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &			operator=( AAnimal const & rhs );

		virtual void		makeSound(void) const = 0;
		const std::string &	getType(void) const;

	protected:
		std::string	type;
};

std::ostream &				operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */