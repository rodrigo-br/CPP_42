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
	if (this != &rhs)
	{
		this->_x = rhs._x;
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Point const &value)
{
	o << value._x;
	return (o);
}