#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5);
	std::cout.width(10); std::cout << std::left << "a: " << a << std::endl;
	std::cout.width(10); std::cout << std::left << "++a: " << ++a << std::endl;
	std::cout.width(10); std::cout << std::left << "a: " << a << std::endl;
	std::cout.width(10); std::cout << std::left << "a++: "<< a++ << std::endl;
	std::cout.width(10); std::cout << std::left << "a: " << a << std::endl;
	std::cout.width(10); std::cout << std::left << "b: " <<  b << std::endl;
	std::cout.width(10); std::cout << std::left << "c: " <<  c << std::endl;
	std::cout.width(10); std::cout << std::left << "max(c,b): " << Fixed::max( c, b ) << std::endl;
	std::cout.width(10); std::cout << std::left << "c + b: " << c + b << std::endl;
	std::cout.width(10); std::cout << std::left << "c - b: " << c - b << std::endl;
	std::cout.width(10); std::cout << std::left << "c * b: " << c * b << std::endl;
	std::cout.width(10); std::cout << std::left << "c / b: " << c / b << std::endl;
	std::cout.width(10); std::cout << std::left << "c > b: " << (c > b) << std::endl;
	std::cout.width(10); std::cout << std::left << "c < b: " << (c < b) << std::endl;
	std::cout.width(10); std::cout << std::left << "c != b: " << (c != b) << std::endl;
	std::cout.width(10); std::cout << std::left << "c == b: " << (c == b) << std::endl;
	std::cout.width(10); std::cout << std::left << "c >= b: " << (c >= b) << std::endl;
	std::cout.width(10); std::cout << std::left << "c <= b: " << (c <= b) << std::endl;
	return 0;
}
