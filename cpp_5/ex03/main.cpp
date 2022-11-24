#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void test_ex_pdf() {
	print_line();
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	Bureaucrat nico("Nico", 1);
	nico.signForm(*rrf);
	nico.executeForm(*rrf);
	delete rrf;
}

void test_invalid() {
	print_line();
	Intern Nico;
	AForm *invalid = Nico.makeForm("cavalinho", "Emily");
	(void)invalid;
}

void test_no_grade() {
	print_line();
	Intern Emily;
	AForm *valid = Emily.makeForm("ShrubberyCreationForm", "Arvri");
	Bureaucrat Nico("Nico");
	try {  Nico.signForm(*valid); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	delete valid;
}

int main(void)
{
	print_line();
	t("* PDF Example test *");	test_ex_pdf();	print_line();
	t("* Invalid form *");		test_invalid();	print_line();
	t("* Valid but no grade *");test_no_grade();print_line();
}