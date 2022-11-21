#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default Ctor" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = (i % 2 == 0) ? "Run" : "Bite";
	}
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain Cpy Ctor" << std::endl;
	*this = src;
}

void Brain::operator=(Brain const &src) {
	std::cout << "Brain Assignment OPtor" << std::endl;
	for (int i = 100; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain Dtor" << std::endl;
}

std::string		Brain::getIdea(int index) const {
	return this->ideas[index];
}

void		Brain::setIdea(std::string idea, int index) {
	this->ideas[index] = idea;
}