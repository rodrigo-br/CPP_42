#include "Cure.hpp"
#include "Ice.hpp"

#include <iostream>

int main (void)
{
	Ice		ice;
	Cure	cure;

	std::cout << ice.getType() << std::endl;
	std::cout << cure.getType() << std::endl;

	Ice *clone = ice.clone();
	std::cout << clone->getType() << std::endl;

	AMateria *tmp = ice.clone();
	std::cout << tmp->getType() << std::endl;
	delete clone;
}
