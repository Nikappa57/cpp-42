#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
#include <fstream>

# define MIN_VAL 0.f
# define MAX_VAL 1000.0f
# define IS_LEAP(Y) ( ((Y) % 4 == 0 && (Y) % 100 != 0) || ((Y) % 400 == 0) )

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		void	loadDB(const std::string & csvFilename);
		void	compare(const std::string & filename);

		const	std::map<std::string, float> & getDb() const;

	private:

		std::map<std::string, float> _db;

		int		checkData(const std::string & date, float outValue, bool db = false) const;
		int		parseLine(const std::string & line, const std::string & del, std::string & outDate, float & outValue) const;
		void	compareLine(const std::string & date, float outValue) const;
		int		daysInMonth(int y, int m) const;
		int		toInt(const std::string & str) const;
};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */