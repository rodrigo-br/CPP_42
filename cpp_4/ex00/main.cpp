#include "Animal.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal	a;
	Animal b(a);
	Animal c = b;
	std::cout << std::string(42, '-') << std::endl;

	Dog		d;
	Dog		e(d);
	Dog		f = e;
	std::cout << std::string(42, '-') << std::endl;

	std::cout << c;
	std::cout << d;
	std::cout << e;
	std::cout << std::string(42, '-') << std::endl;
	return (0);
}