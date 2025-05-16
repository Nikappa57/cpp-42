#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN;

typedef void (RPN::*transFn)(char c);

# define DEBUG 1

class RPN
{

	public:
		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN & operator=( RPN const & rhs );

		int calculate(const std::string & expression);
		
		enum State { I, N, S, OP };

	private:
		// for parsing
		// a state machine, just for fun :)
		State _state;
		static const State _acceptingState;

		static const transFn _tf[];

		// for calculating
		std::stack<int>	_stack;

		void _init_state(char c);
		void _n_state(char c);
		void _s_state(char c);
		void _op_state(char c);
};

std::ostream &			operator<<( std::ostream & o, RPN const & i );
std::ostream &			operator<<( std::ostream & o, RPN::State const & i );


#endif /* ************************************************************* RPN_H */