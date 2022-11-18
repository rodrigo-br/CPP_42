#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	updateDiamond(FragTrap().getHP(), ScavTrap().getEP(), FragTrap().getDMG());
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name), ScavTrap(), FragTrap() {
	std::cout << this->_type << " Named Constructor called" << std::endl;
	updateDiamond(FragTrap().getHP(), ScavTrap().getEP(), FragTrap().getDMG());
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(), FragTrap() {
	std::cout << this->_type << " Copy Constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_type << " Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs.getName();
		updateDiamond(rhs.getHP(), rhs.getEP(), rhs.getDMG());
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &value) {
	o << "Name: " << value.getName() << "\nHP: " << value.getHP() << "\nEP: "
	<< value.getEP() << "\nAttack: " << value.getDMG() << std::endl;
	return o;
}

void DiamondTrap::updateDiamond(int hp, int ep, int dmg) {
	this->setHP(hp);
	this->setEP(ep);
	this->setDMG(dmg);
}

std::string	const	DiamondTrap::_type = "DiamondTrap";