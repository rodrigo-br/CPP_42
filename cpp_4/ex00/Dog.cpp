#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(), type("Dog") {
	std::cout << this->getType() << " Copy Ctor" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(Dog const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	if (this != &src)
		this->type = src.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	Dog::getType() const {
	return this->type;
}

std::ostream	&operator<<(std::ostream &o, Dog const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}