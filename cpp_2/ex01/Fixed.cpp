#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0), _powerOfFractioal(pow(2.0f, (float)this->_fractional)) {
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed::Fixed(const int value) : _powerOfFractioal(pow(2.0f, (float)this->_fractional)) {
	std::cout << "Fixed int overload Constructor called" << std::endl;
	this->_rawBits = value * this->_powerOfFractioal;
}

Fixed::Fixed(const float value) : _powerOfFractioal(pow(2.0f, (float)this->_fractional)) {
	std::cout << "Fixed float overload Constructor called" << std::endl;
	this->_rawBits = value * this->_powerOfFractioal + (value >= 0 ? 0.5 : -0.5);
}

Fixed::Fixed(Fixed const &src) : _powerOfFractioal(pow(2.0f, (float)this->_fractional)) {
	*this = src;
	std::cout << "Fixed's Copy Constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	std::cout << "Fixed's Assignment Operator called" << std::endl;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void 	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float 		Fixed::toFloat( void ) const {
	return ((float)this->_rawBits) / this->_powerOfFractioal;
}

int 		Fixed::toInt( void ) const {
	return this->_rawBits / this->_powerOfFractioal;
}