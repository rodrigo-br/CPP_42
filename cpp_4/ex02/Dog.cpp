#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << this->getType() << " Default Ctor" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog const &src) {
	*this = src;
	std::cout << this->getType() << " Copy Ctor" << std::endl;
}

Dog	&Dog::operator=(Dog const &src) {
	this->type = src.getType();
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	this->brain = new Brain();
	return *this;
}

Dog::~Dog() {
	std::cout << this->getType() << " Dtor" << std::endl;
	delete this->brain;
}

std::string	Dog::getType() const {
	return this->type;
}

void Dog::makeSound() const {
	std::cout << this->getType() << " Barks." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Dog const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}

Brain	*Dog::getBrain() const {
	return this->brain;
}
