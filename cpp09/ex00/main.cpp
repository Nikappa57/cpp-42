#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	BitcoinExchange be;

	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		be.loadDB("data.csv");
		// std::cout << be << std::endl;
		be.compare(argv[1]);
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*
TEST FILE:

date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648

2012-01-11 | 0
2012-01-11 | 1000
2001-01-01 | 10
2025-01-01 | 1

Invalid date tests:
2001-42-42
2011-02-29 | 5
2011-13-01 | 6
2011-00-01 | 7
2-1-0 | 7
-- | 7
2147483648-00-01 | 7
-2147483649-00-01 | 7

Invalid value tests:
2012-01-11 | -1
2012-01-11 | 2147483648
2011-01-01 | -0.1
2012-01-11 | 1000.01
2012-01-11 | 1001


*/