#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << "HumanB Constructor Called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB Destructor Called" << std::endl;
}

void HumanB::attack() const {
	std::cout << this->get_name() << " attacks with their " << this->get_weapon() << std::endl;
}

std::string HumanB::get_name() const {
	return this->_name;
}

std::string HumanB::get_weapon() const {
	if (!this->_weapon)
		return "bare hands";
	return this->_weapon->getType();
}

void HumanB::setWeapon(Weapon & weapon) {
	this->_weapon = &weapon;
}