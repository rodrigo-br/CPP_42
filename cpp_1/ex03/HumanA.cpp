#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon const &weapon) : _name(name), _weapon(weapon) {
	std::cout << "HumanA Constructor Called" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA Destructor Called" << std::endl;
}

void HumanA::attack() const {
	std::cout << this->get_name() << " attacks with their " << this->get_weapon() << std::endl;
}

std::string HumanA::get_name() const {
	return this->_name;
}

std::string HumanA::get_weapon() const {
	return this->_weapon.getType();
}