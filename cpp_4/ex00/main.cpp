#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << std::string(42, '-') << std::endl;
	const Animal	*a = new Animal();
	const Animal 	*b = new Dog();
	const Animal 	*c = new Cat();
	std::cout << std::string(42, '-') << std::endl;

	std::cout << *a;
	std::cout << *b;
	std::cout << *c;

	std::cout << std::string(42, '-') << std::endl;

	a->makeSound();
	b->makeSound();
	c->makeSound();

	std::cout << std::string(42, '-') << std::endl;
	return (0);
}