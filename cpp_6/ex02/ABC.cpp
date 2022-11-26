#include "Base.hpp"

class A : public Base {public: A();};
class B : public Base {public: B();};
class C : public Base {public: C();};


A::A() {
	std::cout << "A constructor called" << std::endl;
}
B::B() {
	std::cout << "B constructor called" << std::endl;
}
C::C() {
	std::cout << "C constructor called" << std::endl;
}

Base *generate(void) {
	srand(time(NULL));
	short choice = rand() % 3;
	if (choice == 0) {
		return new A;
	}
	else if (choice == 1) {
		return new B;
	}
	return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p)) { std::cout << "A"; }
	if (dynamic_cast<B *>(p)) { std::cout << "B"; }
	if (dynamic_cast<C *>(p)) { std::cout << "C"; }
	std::cout << " class identified through pointer" << std::endl;
}

void identify(Base& p) {
	try {
		dynamic_cast<A &>(p);
		std::cout << "A";
	} catch (std::exception &e){}
	try {
		dynamic_cast<B &>(p);
		std::cout << "B";
	} catch (std::exception &e){}
	try {
		dynamic_cast<C &>(p);
		std::cout << "C";
	} catch (std::exception &e){}
	std::cout << " class identified by reference" << std::endl;
}

