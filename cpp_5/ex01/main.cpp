#include "Bureaucrat.hpp"
#include "Form.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void test_cpy_ctor_n_assign() {
	Form a;							print_line();

	std::cout << a;
	std::cout << &a << std::endl;	print_line();

	Form b = a;						t("Assignment Copy");

	std::cout << b;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;	print_line();

	Form c(b);						t("Constructor Copy");

	std::cout << c;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &c << std::endl;
}

void test_sign_n_exec_form() {
	print_line();
	Bureaucrat	Nico("Nico", 100);
	Form		form("Guarda compartilhada do cachorro", 100, 99);

	t("Sign ok");
	Nico.signForm(form);		print_line();

	t("Execute fail");
	try {
		Nico.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	print_line();t("incremeant grade to execute");
	Nico.incrementGrade();
	std::cout << Nico << std::endl;
	Nico.executeForm(form);
}

void test_invalid_grades() {
	Bureaucrat	Emily("Emily");					print_line();
	Form		Normal("Formulário de cachorro normal", 1, 1);

	std::cout << Emily;
	print_line();t("Emily with low grade to sign");
	try { Emily.signForm(Normal); }
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	print_line();t("Emily with grade to execute but form not signed");
	while (Emily.getGrade() > 1) {Emily.incrementGrade();}
	try { Emily.executeForm(Normal); }
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	print_line();
	t("* Copys *");		test_cpy_ctor_n_assign();	print_line();
	t("* Sign Form *");	test_sign_n_exec_form();	print_line();
	t("* Invalids *");	test_invalid_grades();		print_line();
}