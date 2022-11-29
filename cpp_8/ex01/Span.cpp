#include "Span.hpp"
#include <limits>
#include <cstdlib>

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int n) : _capacity(n) {}

void	Span::addNumber(int n) {
	if (this->_storage.size() == this->_capacity)
		throw storageFullException();
	this->_storage.insert(n);
}

void	Span::addMany(std::set<int>::iterator first, std::set<int>::iterator last) {
	while (first != last) {
		if (this->_storage.size() == this->_capacity)
			throw storageFullException();
		this->addNumber(*first);
		first++;
	}
}

static bool decide_compare(int value, bool greater_than, int distance) {
	if (greater_than)
		return value > distance;
	return value < distance;
}

unsigned int Span::compare(int distance) const {
	if (this->_storage.size() < 2)
		throw notEnoughToCompareException();

	bool greater_than = distance < 0 ? true : false;
	std::set<int>::iterator it2;
	std::set<int>::iterator it = this->_storage.begin();
	for (unsigned int i = 0; i < this->_capacity; i++) {
		it2 = this->_storage.begin();
		for (unsigned int j = 0; j < this->_capacity; j++) {
			if (i != j && decide_compare(abs(*it - *it2), greater_than, distance)) {
				distance = abs(*it - *it2);
			}
			it2++;
		}
		it++;
	}
	return (unsigned int)distance;
}

unsigned int	Span::shortestSpan() const {
	return compare(std::numeric_limits<int>::max());
}

unsigned int	Span::longestSpan() const {
	if (this->_storage.size() < 2)
		throw notEnoughToCompareException();
	return abs(*--this->_storage.end() - *this->_storage.begin());
}

const char *Span::storageFullException::what() const throw() {
	return "Fail to add number. No empty space left.\n";
}

const char *Span::notEnoughToCompareException::what() const throw() {
	return "Fail. Need at least 2 numbers in storage to compare.\n";
}

void	Span::showStorage() const {
	std::set<int>::iterator it = this->_storage.begin();

	while (it != this->_storage.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}