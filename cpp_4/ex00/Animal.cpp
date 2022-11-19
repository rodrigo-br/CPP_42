#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

Animal::Animal(Animal const &src) : type("Animal") {
	std::cout << this->getType() << " Copy Ctor" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(Animal const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	if (this != &src)
		this->type = src.getType();
	return *this;
}

Animal::~Animal() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
}

std::ostream	&operator<<(std::ostream &o, Animal const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}