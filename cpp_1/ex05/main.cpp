#include "Harl.hpp"

int main(void)
{
	Harl	harl;

	std::cout << std::string(42, '-') << std::endl;
	harl.complain("INFO");
	std::cout << std::string(42, '-') << std::endl;
	harl.complain("DEBUG");
	std::cout << std::string(42, '-') << std::endl;
	harl.complain("WARNING");
	std::cout << std::string(42, '-') << std::endl;
	harl.complain("ERROR");
	std::cout << std::string(42, '-') << std::endl;
	harl.complain("RANDOM");
}
