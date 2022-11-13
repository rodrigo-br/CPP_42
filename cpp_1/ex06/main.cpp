#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "invalid args" << std::endl;
	}
	std::cout << std::string(42, '-') << std::endl;
	Harl	harl;

	harl.complain(argv[1]);
}
