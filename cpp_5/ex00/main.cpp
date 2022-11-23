#include "Bureaucrat.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void test_copy_constructor() {
	Bureaucrat	a("Nicolau", 120);
	Bureaucrat	b(a);
	Bureaucrat	c;					print_line();

	t("<< Operator");
	std::cout << a;
	std::cout << b;
	std::cout << c;					print_line();

	t("Adresses");
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
}

void test_assign_constructor() {
	Bureaucrat a("Emily", 60);
	Bureaucrat b;
	b = a;							print_line();

	t("<< Operator");
	std::cout << a;
	std::cout << b;					print_line();

	t("Adresses");
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
}

void test_exceptions() {
									print_line();
	try {
		std::cout << "Trying: Bureaucrat a(151)" << std::endl;
		Bureaucrat a(151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
									print_line();
	try {
		std::cout << "Trying: Bureaucrat a(0)" << std::endl;
		Bureaucrat a(0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
									print_line();
	try {
		std::cout << "Trying: Bureaucrat a(-5)" << std::endl;
		Bureaucrat a(-5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void test_in_decrement() {
	Bureaucrat	a(100);					print_line();

	std::cout << a;
	std::cout << "Testing Increment: " << std::endl;
	a.incrementGrade();
	std::cout << a;
	std::cout << "Testing Decrement: " << std::endl;
	a.decrementGrade();
	std::cout << a;
}

void test_invalid_operations() {
										print_line();
	try {
		std::cout << "Trying Increment grade 1 Bureaucrat" << std::endl;
		Bureaucrat	a(1);
		a.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
										print_line();
	try {
		std::cout << "Trying Decrement grade 150 Bureaucrat" << std::endl;
		Bureaucrat	a(150);
		a.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	print_line();
	t("* Cpy Ctor *");		test_copy_constructor();	print_line();
	t("* Assign Ctors *");	test_assign_constructor();	print_line();
	t("* Exceptions *");	test_exceptions();			print_line();
	t("* In/Decrement *");	test_in_decrement();		print_line();
	t("* Invalid Ops *");	test_invalid_operations();	print_line();
}