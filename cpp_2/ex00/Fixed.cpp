#include "Fixed.hpp"

Fixed::Fixed() {
	this->_rawBits = 0;
	std::cout << "Fixed Constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
	std::cout << "Fixed's Copy Constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	std::cout << "Fixed's Assignment Operator called" << std::endl;
	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void 	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}