#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	ScavTrap::_energyPoints = 50;//since fragtrap's constructor comes last, it overrides the scavtrap default value
	updateDiamond(FragTrap::getHP(), ScavTrap::getEP(), FragTrap::getDMG());
}

DiamondTrap::DiamondTrap(std::string const name) :
ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name") {
	std::cout << this->_type << " Named Constructor called" << std::endl;
	ScavTrap::_energyPoints = 50;
	this->_name = name;
	updateDiamond(FragTrap::getHP(), ScavTrap::getEP(), FragTrap::getDMG());
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) :
ClapTrap(src._name + "_clap_name"), ScavTrap(src._name + "_scav_name"), FragTrap(src._name + "_frag_name") {
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

std::string DiamondTrap::getName() const {
	return this->_name;
}

void DiamondTrap::updateDiamond(int hp, int ep, int dmg) {
	this->setHP(hp);
	this->setEP(ep);
	this->setDMG(dmg);
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->getName() << ", and my ClapTrap Name is "
	<< this->ClapTrap::getName() << std::endl;
}

std::string	const	DiamondTrap::_type = "DiamondTrap";