#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : type("WrongAnimal") {
	std::cout << this->getType() << " Copy Ctor" << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	if (this != &src)
		this->type = src.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "..." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, WrongAnimal const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}