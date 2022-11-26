#include "iter.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

int main(void)
{
	{
		print_line(); t("Test with array of CHAR");
		char x[5] = {'a', 'b', 'c', 'd', 'e'};
		std::cout << "print_element function :\n"; 
		iter(x, 5, print_element);
		std::cout << "sum_element function :\n"; 
		iter(x, 5, sum_element);
	}

	{
		print_line(); t("Test with array of FLOAT");
		float x[5] = {1.0f, 2.5f, 3.3f, 4.9f, 5000.1f};
		std::cout << "print_element function :\n"; 
		iter(x, 5, print_element);
		std::cout << "sum_element function :\n"; 
		iter(x, 5, sum_element);
	}

	{
		print_line(); t("Test with array of STRING");
		std::string x[5] = {"A", "Emily", "é", "uma", "cachorra"};
		std::cout << "print_element function :\n"; 
		iter(x, 5, print_element);
		std::cout << "sum_element function :\n"; 
		iter(x, 5, sum_element);
	}
	
}