#include "BitcoinExchange.hpp"
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <cerrno>
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR and DESTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ) { *this = src; }

BitcoinExchange::~BitcoinExchange() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs ) { 
	if ( this != &rhs )
	{
		// Copy the contents of rhs to this object
		this->_db = rhs._db;
	}
	return *this;
}

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & i )
{
	o << "BitcoinExchange, databse: " << std::endl;
	std::map<std::string, float>::const_iterator it = i.getDb().begin();
	for (; it != i.getDb().end(); ++it) {
		o << it->first << ": " << it->second << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::loadDB(const std::string & csvFilename) {
	std::ifstream infile(csvFilename.c_str());
	if (infile.fail()) {
		throw std::runtime_error("Error: could not open db file.");
	}
	std::string line;
	getline(infile, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: bad header in db file.");
	while (std::getline(infile, line)) {
		std::string date;
		float value;
		if ((parseLine(line, ",", date, value) != 0)
			|| (checkData(date, value, true) != 0))
			throw std::runtime_error("Error: bad input in db => " + line);
		_db[date] = value;
	}
	infile.close();
}

void BitcoinExchange::compare(const std::string & csvFilename) {
	std::ifstream infile(csvFilename.c_str());
	if (infile.fail()) {
		throw std::runtime_error("Error: could not open file.");
	}
	std::string line;
	getline(infile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: bad header in file.");
	while (std::getline(infile, line)) {
		std::string date;
		float value;
		if ((parseLine(line, " | ", date, value) != 0)
			|| (checkData(date, value) != 0)) continue;
		compareLine(date, value);
	}
}

void BitcoinExchange::compareLine(const std::string & date, float outValue) const {
	// lower_bound return the value for the closest date in the database
	// if the date is not found, it returns the first elememnt that is greater than the date
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date) { // if not found or not exact match
		if (it == _db.begin()) {
			std::cerr << "Error: no data for date " << date << std::endl;
			return;
		}
		--it; // go to the previous element
	}
	float result = it->second * outValue;
	std::cout << date << " => " << outValue << " = "
		<< std::setprecision(4) << result << std::endl;
}

int BitcoinExchange::parseLine(const std::string & line, const std::string & del,
		std::string & outDate, float & outValue) const {
	if (line.empty()) {
		std::cerr << "Error: empty line" << std::endl;
		return (-1);
	}
	size_t pos = line.find(del);
	if (pos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (-1);
	}
	outDate = line.substr(0, pos);
	std::string valueStr = line.substr(pos + del.length());
	char *end;
	outValue = strtof(valueStr.c_str(), &end);
	if (*end != '\0' || errno == ERANGE) {
		std::cerr << "Error: Invalid value " << line << std::endl;
		return (-1);
	}
	return 0;
}

int BitcoinExchange::daysInMonth(int y, int m) const {
	static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2)
		return days[1] + (IS_LEAP(y) ? 1 : 0);
	return days[m - 1];
}

// return -1 if the conversion fails
int BitcoinExchange::toInt(const std::string & str) const {
	char * end;
	long temp_value = strtol(str.c_str(), &end, 10);
	// check errors
	if (*end != '\0' || errno == ERANGE)
		return (-1);
	// check if the value is in the range of int
	if (temp_value > std::numeric_limits<int>::max()
		|| temp_value < std::numeric_limits<int>::min())
		// out of range => long => type not supported
		return (-1);
	// convert to int
	return (static_cast<int>(temp_value));
}

int BitcoinExchange::checkData(const std::string & date, float outValue, bool db) const {
	// check value
	if ((outValue > MAX_VAL) && !db) {
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}
	if (outValue < MIN_VAL) {
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	// check date format
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return -1;
	}
	int year = toInt(date.substr(0, 4));
	int month = toInt(date.substr(5, 2));
	int day = toInt(date.substr(8, 2));
	if (year < 0 || month < 1 || month > 12 || day < 1) {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return -1;
	}
	if (day > daysInMonth(year, month)) {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return -1;
	}
	return 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::map<std::string, float> & BitcoinExchange::getDb() const {
	return this->_db;
}


/* ************************************************************************** */