#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <exception>

template <typename T>
class Array
{

	public:

		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(const Array<T> & src);
		~Array<T>();

		Array<T> & operator=(const Array<T> & rhs);
		T & operator[](int index) const;

		unsigned int size(void) const;

		// out of bounds exception
		class OutOfBoundsException : public std::exception
		{
			private:
				std::string _msg;

			public:
				OutOfBoundsException(const Array<T> & arr, int index) {
					std::ostringstream temp;
					temp << "Out of bounds exception: index " 
						<< index << " for array of size " << arr.size();
					_msg = temp.str();
				}

				virtual ~OutOfBoundsException() throw() {}
				
				const char * what() const throw() {
					return _msg.c_str();
				}
		};

	private:
		T *				_arr;
		unsigned int	_n;
};

template <typename T>
std::ostream & operator<<( std::ostream & o, Array<T> const & i );

# include "Array.tpp"

#endif /* *********************************************************** ARRAY_H */