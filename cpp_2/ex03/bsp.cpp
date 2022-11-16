#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	std::cout << "AQUI" << c.getY() << "\n" << a.getY() << std::endl;
	Fixed s1 = c.getY() - a.getY();
	Fixed s2 = c.getX() - a.getX();
	Fixed s3 = b.getY() - a.getY();
	Fixed s4 = point.getY() - a.getY();
	// std::cout << "s1 = " << s1 << std::endl;
	// std::cout << "s2 = " << s2 << std::endl;
	// std::cout << "s3 = " << s3 << std::endl;
	// std::cout << "s4 = " << s4 << std::endl;

	Fixed w1 = (a.getX() * s1 + s4 * s2 - point.getX()) / (s3 * s2 - (b.getX() - a.getX()) * s1);
	Fixed w2 = (s4 - w1 * s3) / s1;
	// std::cout << w1 << "\n" << w2 << std::endl;
	return w1 > 0 && w2 > 0 && (w1 + w2) < 1;
}
