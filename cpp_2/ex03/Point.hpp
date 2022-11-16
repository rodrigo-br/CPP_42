#pragma once
#ifndef POINT_H
# define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
		
	public:

		Point();
		Point(Point const &src);
		Point(float const x, float const y);
		~Point();

		const Point &operator=(Point const &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream				&operator<<(std::ostream &o, Point const &value);

#endif