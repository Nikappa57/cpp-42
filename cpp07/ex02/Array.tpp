#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array(void) : _arr(NULL), _n(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : _n(n) {
	if (_n > 0)
		_arr = new T[_n];
	else
		_arr = NULL;
}

template <typename T>
Array<T>::Array( const Array<T> & src ) : _arr(NULL) {
	*this = src; // delegate to assignment operator
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array() {
	if (_arr)
		delete [] _arr;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
Array<T> & Array<T>::operator=( Array<T> const & rhs ) {
	if ( this != &rhs ) {
		if (_arr)
			delete [] _arr;
		_n = rhs.size();
		if (_n) {
			_arr = new T[_n];
			for (unsigned i = 0; i < _n; i++)
				_arr[i] = rhs[i];
		} else {
			_arr = NULL;
		}
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](int index ) const {
	if (index < 0)
		throw OutOfBoundsException(*this, index);
	if (static_cast<unsigned int>(index) >= _n)
		throw OutOfBoundsException(*this, index);
	return _arr[index];
}

template <typename T>
std::ostream & operator<<( std::ostream & o, Array<T> const & i )
{
	o << "Arr [" << i.size() << "] : ";
	for (int j = 0; j < i.size(); j++)
		o << i[j] << " ";
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template <typename T>
unsigned int Array<T>::size(void) const {
	return _n;
}


/* ************************************************************************** */