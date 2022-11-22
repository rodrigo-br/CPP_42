#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(Ice const &src) : AMateria(src.getType()) {
}

Ice::~Ice() {
}

Ice* Ice::clone() const {
	return new Ice();
}
