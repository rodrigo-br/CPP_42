#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << this->_type << " Default Constructor called" << std::endl;
	updateFrag(100, 100, 30);
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	std::cout << this->_type << " Named Constructor called" << std::endl;
	updateFrag(100, 100, 30);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << this->_type << " Copy Constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << this->_type << " Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs.getName();
		updateFrag(rhs.getHP(), rhs.getEP(), rhs.getDMG());
	}
	return *this;
}

void FragTrap::updateFrag(int hp, int ep, int dmg) {
	this->setHP(hp);
	this->setEP(ep);
	this->setDMG(dmg);
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->_type << " " << this->_name << " request a positive high five" << std::endl;
}

std::string		const	FragTrap::_type = "FragTrap";