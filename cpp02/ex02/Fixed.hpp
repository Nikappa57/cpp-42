#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
	/*
	 *	Fixed-Point
	 *	raw = n * 2^f_bits = n << f_bits
	 *	n = raw / 2^f_bits = raw >> f_bits
	 *	for float raw: n = raw / 2^f_bits = raw / (1 << f_bits)
	 */

	public:

		Fixed();
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed&					operator=( Fixed const & rhs );
		Fixed					operator+(const Fixed &other) const;
		Fixed					operator-(const Fixed &other) const;
		Fixed					operator*(const Fixed &other) const;
		Fixed					operator/(const Fixed &other) const;

		Fixed					operator++(int);
		Fixed &					operator++(void);
		Fixed					operator--(int);
		Fixed &					operator--(void);

		bool					operator>(const Fixed &other) const;
		bool					operator<(const Fixed &other) const;
		bool					operator>=(const Fixed &other) const;
		bool					operator<=(const Fixed &other) const;
		bool					operator==(const Fixed &other) const;
		bool					operator!=(const Fixed &other) const;

		static Fixed &			min(Fixed &a, Fixed &b);
		static const Fixed &	min(const Fixed &a, const Fixed &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static const Fixed &	max(const Fixed &a, const Fixed &b);

		int						getRawBits( void ) const;
		void					setRawBits( int const raw );

		float					toFloat( void ) const;
		int						toInt( void ) const;

	private:
		int						value;
		static const int		f_bits = 8;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */