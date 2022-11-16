#include "Fixed.hpp"

Fixed::Fixed() : 
_rawBits(0),
_powerOfFractional(pow(2.0f, (float)this->_fractional)) {
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int value) : _powerOfFractional(pow(2.0f, (float)this->_fractional)) {
	this->_rawBits = value * this->_powerOfFractional;
}

Fixed::Fixed(const float value) : _powerOfFractional(pow(2.0f, (float)this->_fractional)) {
	this->_rawBits = value * this->_powerOfFractional + (value >= 0 ? 0.5 : -0.5);
}

Fixed::Fixed(Fixed const &src) : _powerOfFractional(pow(2.0f, (float)this->_fractional)) {
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) {
	Fixed	result(this->toFloat() + rhs.toFloat());
	return result;
}

Fixed Fixed::operator-(Fixed const &rhs) {
	Fixed	result(this->toFloat() - rhs.toFloat());
	return result;
}

Fixed Fixed::operator*(Fixed const &rhs) {
	Fixed	result(this->toFloat() * rhs.toFloat());
	return result;
}

Fixed Fixed::operator/(Fixed const &rhs) {
	Fixed	result(this->toFloat() / rhs.toFloat());
	return result;
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed newFixed = *this;
	this->setRawBits(this->getRawBits() + 1);
	return newFixed;
}

bool Fixed::operator<(Fixed const &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

std::ostream		&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}

int		Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

void 	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float 		Fixed::toFloat( void ) const {
	return ((float)this->_rawBits) / this->_powerOfFractional;
}

int 		Fixed::toInt( void ) const {
	return this->_rawBits / this->_powerOfFractional;
}

Fixed &Fixed::max(Fixed &firt,Fixed &right) {
	if (firt > right)
		return firt;
	return right;
}

Fixed const &Fixed::max(Fixed const &firt, Fixed const &right) {
	if (firt > right)
		return firt;
	return right;
}
