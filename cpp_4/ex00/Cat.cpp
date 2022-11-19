#include "Cat.hpp"

Cat::Cat() : type("Cat") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(), type("Cat") {
	std::cout << this->getType() << " Copy Ctor" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(Cat const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	if (this != &src)
		this->type = src.getType();
	return *this;
}

Cat::~Cat() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	Cat::getType() const {
	return this->type;
}

void Cat::makeSound() const {
	std::cout << this->getType() << " Meows." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Cat const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}