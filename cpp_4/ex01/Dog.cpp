#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
	this->_brain = new Brain();
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
	delete this->_brain;
}

std::string	Dog::getType() const {
	return this->type;
}

void Dog::makeSound() const {
	std::cout << this->getType() << " Barks." << std::endl;
}

Brain	Dog::useBrain() {
	return *this->_brain;
}

std::ostream	&operator<<(std::ostream &o, Dog const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}