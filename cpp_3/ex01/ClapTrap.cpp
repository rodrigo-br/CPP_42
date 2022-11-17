#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("Nameless"), _hitPoints(10), _energyPoints(10), _attackDmg(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) :
_name(name), _hitPoints(10), _energyPoints(10), _attackDmg(0) {
	std::cout << "ClapTrap Named Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs)
		const_cast<std::string &>(this->_name) = rhs._name;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " 
	<< this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " loses " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0)
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of damage!" << std::endl;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

int ClapTrap::getHP() const {
	return this->_hitPoints;
}

int ClapTrap::getEP() const {
	return this->_energyPoints;
}

int	ClapTrap::getDMG() const {
	return this->_attackDmg;
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &value) {
	o << "Name: " << value.getName() << "\nHP: " << value.getHP() << "\nEP: " << value.getEP() << std::endl;
	return o;
}
