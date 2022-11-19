#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::string(42, '-') << std::endl;
	const Animal	*a = new Animal();
	const Animal 	*b = new Dog();
	const Animal 	*c = new Cat();
	std::cout << std::string(42, '-') << std::endl;

	std::cout << "a = " << *a;
	std::cout << "b = " << *b;
	std::cout << "c = " << *c;

	std::cout << std::string(42, '-') << std::endl;

	std::cout << "a = ";	a->makeSound();
	std::cout << "b = ";	b->makeSound();
	std::cout << "c = ";	c->makeSound();

	std::cout << std::string(42, '-') << std::endl;

	const WrongAnimal	*wrongcat = new WrongCat();
	std::cout << std::string(42, '-') << std::endl;

	std::cout << "WrongCat = " << *wrongcat;
	wrongcat->makeSound();

	std::cout << std::string(42, '-') << std::endl;
	delete a;
	delete b;
	delete c;
	delete wrongcat;
	return (0);
}