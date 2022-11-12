#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon Constructor Called." << std::endl; 
}

Weapon::~Weapon()
{
	std::cout << "Weapon Destructor Called." << std::endl; 
}

std::string Weapon::getType() {
	return this->_type;
}

void		Weapon::setType(std::string new_type) {
	this->_type = new_type;
}
