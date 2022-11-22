#include "Character.hpp"

Character::Character() : ICharacter(), _name("Doe"), _nOfMaterials(0) {
}

Character::Character(std::string name) : ICharacter(), _name(name) {
}

Character::~Character() {
}

std::string const &Character::getName() {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	if (this->_nOfMaterials >= 4)
		return ;
	this->_inventory[_nOfMaterials] = m;
	this->_nOfMaterials++;
}

void	Character::use(int idx, ICharacter& target) {
	this->_inventory[idx]->use(target);
}
