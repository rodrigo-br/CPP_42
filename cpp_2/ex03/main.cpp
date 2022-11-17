#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	const A(1, 2);
	Point	const B(5, 1);
	Point	const C(6, 3);

	// DENTRO DO TRIÂNGULO
	Point	point_1(2, 2);
	std::cout << bsp(A, B, C, point_1) << std::endl;
	Point	point_2(5, 2);
	std::cout << bsp(A, B, C, point_2) << std::endl;

	// FORA DO TRIÂNGULO
	Point	point_3(2, 5);
	std::cout << bsp(A, B, C, point_3) << std::endl;
	Point	point_4(6, 3);
	std::cout << bsp(A, B, C, point_3) << std::endl;
	return 0;
}
