#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <set>
# include <iterator>
# include <algorithm>
# include <limits>

class Span
{

	public:

		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=( Span const & rhs );

		void addNumber(int n); // O(log(n))
		
		template<typename Iter>
		void addNumber(Iter begin, Iter end) {
			// std::distance = number of elements
			if (static_cast<std::size_t>(std::distance(begin, end)) > _limit - _numbers.size()) {
				throw Span::FullException();
			}
			_numbers.insert(begin, end);
		}

		unsigned int shortestSpan() const; // O(n)
		unsigned int longestSpan() const; // O(1)

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