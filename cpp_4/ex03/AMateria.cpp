#include "AMateria.hpp"

AMateria::AMateria() : _type("Amateria") {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const {
	return this->_type;
}
