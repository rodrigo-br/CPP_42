#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(), _nOfKnownMaterials(0) {
	for (int i = 0; i < 4; i++) { this->_known_materials[i] = NULL; }
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < this->_nOfKnownMaterials; i++) {
		delete this->_known_materials[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &src) {
	(void)src; // SOCORRO
}

void	MateriaSource::learnMateria(AMateria *materia) {
	if (this->_nOfKnownMaterials >= 4) {
		std::cout << "Materia Source have no space left to learn any more materia." << std::endl;
		return ;
	}
	this->_known_materials[this->_nOfKnownMaterials] = materia;
	this->_nOfKnownMaterials++;
}

AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < this->_nOfKnownMaterials; i++) {
		if (this->_known_materials[i]->getType().compare(type) == 0)
			return this->_known_materials[i];
	}
	std::cout << "This Materia type is unkown." << std::endl;
	return (0);
}