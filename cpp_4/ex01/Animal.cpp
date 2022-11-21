#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

Animal::Animal(Animal const &src) : type("Animal") {
	*this = src;
	std::cout << this->getType() << " Copy Ctor" << std::endl;
}

Animal	&Animal::operator=(Animal const &src) {
	this->type = src.getType();
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << "..." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Animal const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}
