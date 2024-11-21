# include <fstream>
# include <iostream>
# include <string>
# include <cerrno>
# include <cstring>

# define handle_error(msg) \
	do { std::cerr << msg << std::endl; \
		exit(EXIT_FAILURE); } while (0)

# define handle_perror(msg) \
	do { std::cerr << msg << ": " << strerror(errno) << std::endl; \
		exit(EXIT_FAILURE); } while (0)

int main(int argc, char **argv) {
	if (argc != 4) handle_error("Usage: ./replace <filename> <s1> <s2>");

	std::ifstream input(argv[1]);
	if (!input.is_open()) handle_perror("Failed to open file");

	std::string filename = argv[1];
	filename += ".replace";
	std::ofstream output(filename);
	if (!output.is_open()) {
		input.close();
		handle_perror("Failed to open file");
	}

	size_t		index;
	std::string	data;
	if (std::getline(input, data, '\0')) {
		while (true) {
			index = data.find(argv[2]);
			std::string temp = data.substr(0,
					index != std::string::npos ? index : data.length());
			output << temp;
			if (index == std::string::npos) break;
			output << argv[3];
			data = data.substr(index + strlen(argv[2]));
		}
	} else {
		std::cout << "File is empty" << std::endl;
	}
	
	input.close();
	output.close();

	return 0;
}
