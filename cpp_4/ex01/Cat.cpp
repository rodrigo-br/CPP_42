#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << this->getType() << " Default Ctor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src) {
	*this = src;
	std::cout << this->getType() << " Copy Ctor" << std::endl;
}

Cat	&Cat::operator=(Cat const &src) {
	this->type = src.getType();
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	this->brain = new Brain();
	return *this;
}

Cat::~Cat() {
	std::cout << this->getType() << " Dtor" << std::endl;
	delete this->brain;
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

Brain	*Cat::getBrain() const {
	return this->brain;
}
