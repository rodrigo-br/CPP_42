#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "invalid args" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << std::string(42, '-') << std::endl;
	Harl	harl;

	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}
