#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie Constructor called. " << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Destructor called. " << this->_name << " is now dead, lol" << std::endl;
}

void Zombie::announce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::choose_name(std::string name) {
	this->_name = name;
}