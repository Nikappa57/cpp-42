# include <fstream>
# include <iostream>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>

# define handle_error(msg) \
	do { std::cerr << msg << std::endl; \
		exit(1); } while (0)

# define handle_perror(msg) \
	do { std::cerr << msg << ": " << strerror(errno) << std::endl; \
		exit(1); } while (0)

int main(int argc, char **argv) {
	if (argc != 4) handle_error("Usage: ./replace <filename> <s1> <s2>");

	std::string filename_input = argv[1];
	std::ifstream input(filename_input.c_str());
	if (!input.is_open()) handle_perror("Failed to open file");

	std::string filename_output = filename_input + ".replace";
	std::ofstream output(filename_output.c_str());
	if (!output.is_open()) {
		input.close();
		handle_perror("Failed to open file");
	}

	size_t		index;
	std::string	data;
	std::string	s1 = argv[2];
	if (std::getline(input, data, '\0')) {
		while (true) {
			index = data.find(s1);
			std::string temp = data.substr(0,
					index != std::string::npos ? index : data.length());
			output << temp;
			if (index == std::string::npos) break;
			output << argv[3];
			data = data.substr(index + s1.length());
		}
	} else {
		std::cout << "File is empty" << std::endl;
	}

	input.close();
	output.close();

	return 0;
}
