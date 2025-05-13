#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

/* 
 * https://github.com/qingqingqingli/CPP/wiki/Module08
 * Stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific
 * container class as its underlying container, providing a specific set of member functions to access its elements.
 *
 * https://en.cppreference.com/w/cpp/container/stack
 * The default container is deque.
 * template<class T, class Container = std::deque<T>> class stack;
 * this->c is the actual container used to store the elements of the stack (deque by default).
 * 
 * The deque container iterator is a random access iterator, so it provides all features required by the subject test.
 * 
 * Only a specific set of functions is provided.
 * We are going to add iterators to the stack by exposing the iterators of the underlying container.
 */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack()							: std::stack<T, Container>() {}
		MutantStack(MutantStack const & src)	: std::stack<T, Container>(src) {}
		~MutantStack() {}

		MutantStack& operator=(MutantStack const& other) { std::stack<T, Container>::operator=(other); return *this; }

		iterator begin()						{ return this->c.begin(); }
		iterator end()							{ return this->c.end(); }

		const_iterator begin() const			{ return this->c.begin(); }
		const_iterator end() const				{ return this->c.end(); }

		reverse_iterator rbegin()				{ return this->c.rbegin(); }
		reverse_iterator rend()					{ return this->c.rend(); }

		const_reverse_iterator rbegin() const	{ return this->c.rbegin(); }
		const_reverse_iterator rend() const		{ return this->c.rend(); }
};

template <typename T>
std::ostream & operator<<(std::ostream & o, MutantStack<T> const & i);

#endif /* ***************************************************** MUTANTSTACK_H */