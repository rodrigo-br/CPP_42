#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::~Point() {
}

Point::Point(Point const &src) : _x(0), _y(0) {
	*this = src;
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

const Point &Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		const_cast<Fixed &>(this->_x) = rhs._x;
		const_cast<Fixed &>(this->_y) = rhs._y;
	}
	return *this;
}

Fixed	Point::getX(void) const {
	return this->_x;
}

Fixed	Point::getY(void) const {
	return this->_y;
}

std::ostream		&operator<<(std::ostream &o, Point const &value)
{
	o << "x = " << value.getX() << "\ny = " << value.getY();
	return (o);
}