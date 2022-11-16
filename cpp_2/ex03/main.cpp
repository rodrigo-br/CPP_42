#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	A(-3, -7);
	Point	B(10, 0);
	Point	C(-10, 6);
	Point	point(0, 0);

	//std::cout << A << "\n--------\n" << B << "\n--------\n" << C << "\n--------\n" << point << std::endl;
	std::cout << bsp(A, B, C, point) << std::endl;
	return 0;
}
