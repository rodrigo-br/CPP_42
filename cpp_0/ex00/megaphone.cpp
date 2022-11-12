#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
	int		size;

	if (argc < 2) { std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; }
	for (int i = 1; i < argc; i++) {
		size = strlen(argv[i]);
		for (int j = 0; j < size; j++) {
			std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
