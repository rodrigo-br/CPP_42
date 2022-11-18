#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << this->_type << " Default Constructor called" << std::endl;
	updateScav(100, 50, 20);
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
	std::cout << this->_type << " Named Constructor called" << std::endl;
	updateScav(100, 50, 20);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << this->_type << " Copy Constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << this->_type << " Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs) {
		const_cast<std::string &>(this->_name) = rhs.getName();
		updateScav(rhs.getHP(), rhs.getEP(), rhs.getDMG());
	}
	return *this;
}

void ScavTrap::updateScav(int hp, int ep, int dmg) {
	this->setHP(hp);
	this->setEP(ep);
	this->setDMG(dmg);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0)
		return ;
	std::cout << this->_type << " " << this->_name << " attacks " << target << ", causing " 
	<< this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate() {
	std::cout << this->_type << " " << this->_name << " is now in Gate keeper mode." << std::endl;
}

std::string		const	ScavTrap::_type = "ScavTrap";