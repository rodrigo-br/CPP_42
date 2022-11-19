#include "Cat.hpp"

class Animal;

Cat::Cat() : Animal("Cat"), type("Cat") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << this->getType() << " Deep Copy Ctor" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(Cat const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	this->type = src.getType();
	this->_brain = new Brain();
	return *this;
}

Cat::~Cat() {
	std::cout << this->getType() << " Dtor" << std::endl;
	delete this->_brain;
}

std::string	Cat::getType() const {
	return this->type;
}

void Cat::makeSound() const {
	std::cout << this->getType() << " Meows." << std::endl;
}

Brain	Cat::useBrain() {
	return *this->_brain;
}

std::ostream	&operator<<(std::ostream &o, Cat const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}
