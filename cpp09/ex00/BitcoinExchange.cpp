#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR --------------------------------
*/

// TODO: ricordati di gestire per bene gli anni bisestili ecc

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ) { *this = src; }

BitcoinExchange::~BitcoinExchange() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) { return *this; }

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */