#include "Character.hpp"

Character::Character() :
	ICharacter(), _name("Doe"), _nOfMaterials(0) {
}

Character::Character(std::string name) :
	ICharacter(), _name(name), _nOfMaterials(0) {
}

Character::Character(Character const &src) {
	*this = src;
}

Character::~Character() {
	for (int i = 0; i < this->_nOfMaterials; i++) {
		delete this->_inventory[i];
	}
}

std::string	const &Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	this->_inventory[_nOfMaterials] = m->clone();
	this->_nOfMaterials++;
	Character::materialsOnFloor--;
}

void	Character::use(int idx, ICharacter& target) {
	this->_inventory[idx]->use(target);
}

void	Character::unequip(int idx) {
	for (int i = 0; i < 10; i++) {
		if (Character::floor[i] == NULL) {
			Character::floor[i] = this->_inventory[idx];
			this->_inventory[idx] = NULL;
			return ;
		}
	}
}

AMateria*	Character::getMateriaFromFloor() {
	if (!Character::materialsOnFloor) {
		std::cout << "There aren't avaiable materia on the floor" << std::endl;
		return (NULL);
	}
	int idx = 0;
	for (; idx < 10; idx++) {
		if (Character::floor[idx] != NULL) { break ;}
	}
	return Character::getMateriaFromFloor(idx);
}

AMateria*	Character::getMateriaFromFloor(int idx) {
	if (this->_nOfMaterials >= 4) {
		std::cout << this->getName() << "'s inventory is full." << std::endl;
		return (NULL);
	}
	if (Character::floor[idx] == NULL) {
		std::cout << "This space is empty" << std::endl;
		return (NULL);
	}
	AMateria *found_material = floor[idx];
	Character::floor[idx] = NULL;
	return found_material;
}

int	Character::getNofMaterials() const {
	return this->_nOfMaterials;
}

int			Character::materialsOnFloor = 10;
AMateria	*Character::floor[10] = {
						new Ice(), new Ice(), new Ice(), new Ice(), new Ice(),
						new Cure(), new Cure(), new Cure(), new Cure(), new Cure()};