#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define IDEAS_N 100

class Brain {

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &				operator=( Brain const & rhs );

		const std::string &	getIdea(int i) const;
		void				setIdea(int i, std::string idea);

	private:

		std::string	ideas[IDEAS_N];

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */