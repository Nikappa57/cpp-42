#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <set>

class Span
{

	public:

		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=( Span const & rhs );

		void addNumber(int n); // O(log(n))
		
		template<typename It>
		void addNumber(It begin, It end) {
			for (; begin != end; ++begin)
				addNumber(*begin);
		}

		int shortestSpan() const; // O(n)
		int longestSpan() const; // O(1)

		class FullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Span is full.");
				}
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Not enough numbers have been added.");
				}
		};

	private:
		unsigned int		_limit;
		std::multiset<int>	_numbers;

		Span();

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */