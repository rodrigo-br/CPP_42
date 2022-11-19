#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal	*animals[4];
	// Cat		*cat;
	// Cat		*schrodinger;

	for (int i = 0; i < 4; i++) {
		if (i < 2) {animals[i] = new Dog();}
		else {animals[i] = new Cat();}
	}
	for (int i = 0; i < 4; i++) {
		std::cout << "animals [" << i << "] = " << *animals[i];
	}

	// cat = new Cat();
	// std::cout << cat->useBrain().getIdea(1) << std::endl;

	// schrodinger = cat;

	// std::cout << cat << std::endl;
	// std::cout << schrodinger << std::endl;

	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	// delete cat;
	return (0);
}