#include <iostream>
#include <string>
#include "Convert.hpp"

#define SUCCESS 0

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Wrong number of arguments. Try just one." << std::endl;
		return 666;
	}

	std::string str = argv[1];

	Convert a(str);

	std::cout << a;
	print_line();
	return SUCCESS;
}
