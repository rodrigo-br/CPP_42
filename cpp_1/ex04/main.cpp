#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "wrong args" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string		file = argv[1];
	std::ifstream	ifs(file, std::ifstream::in);
	if (ifs.fail()) {
		std::cerr << "wrong file" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream	ofs(file + ".replace", std::ofstream::out | std::ofstream::app);
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		line;
	size_t			pos;
	while (!ifs.eof()) {
		std::getline(ifs, line);
		pos = line.find(s1, 0);
		if (pos < line.length()) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		ofs << line << std::endl;
	}
	return (EXIT_SUCCESS);
}
