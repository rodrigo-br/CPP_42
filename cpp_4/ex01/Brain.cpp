#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = (i % 2 == 0) ? "Run" : "Bite";
	}
	std::cout << "Brain Default Ctor" << std::endl;
}

Brain::Brain(Brain const &src) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain Cpy Ctor" << std::endl;
}

Brain	&Brain::operator=(Brain const &src) {
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Dtor" << std::endl;
}

std::string	Brain::getIdea(int i) {
	return this->ideas[i];
}