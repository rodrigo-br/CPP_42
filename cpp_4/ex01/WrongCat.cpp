#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat") {
	std::cout << this->getType() << " Default Ctor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(), type("WrongCat") {
	std::cout << this->getType() << " Copy Ctor" << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(WrongCat const &src) {
	std::cout << this->getType() << " Assignment OPtor" << std::endl;
	if (this != &src)
		this->type = src.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << this->getType() << " Dtor" << std::endl;
}

std::string	WrongCat::getType() const {
	return this->type;
}

void WrongCat::makeSound() const {
	std::cout << this->getType() << " Meows." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, WrongCat const &value) {
	o << "Eu sou um " << value.getType() << std::endl;
	return o;
}