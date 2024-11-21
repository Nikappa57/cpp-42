#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define LEVEL_N 4

class Harl {

	public:

		Harl();
		~Harl();

		void	complain( std::string level );

	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		static const std::string levels[LEVEL_N];
		typedef void (Harl::*HarlMemFn)(void);
		static const HarlMemFn functions[LEVEL_N];

};

#endif /* ************************************************************ HARL_H */