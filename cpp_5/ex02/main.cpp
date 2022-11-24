#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void test_valid() {
	Bureaucrat Nico("Nicolau", 1);
	Bureaucrat Emily("Emily", 25);

	print_line(); t("Bureaucrats infos");
	std::cout << Nico << Emily;

	print_line(); t("Shrubbery Form");
	AForm	*a = new ShrubberyCreationForm("arvri");
	std::cout << *a;
	Nico.signForm(*a);
	Emily.executeForm(*a);
	delete a;

	print_line(); t("Robotomy Form");
	RobotomyRequestForm b("Nicolauvsk");
	std::cout << b;
	Emily.signForm(b);
	Nico.executeForm(b);

	print_line(); t("Pardon Form");
	PresidentialPardonForm c("Emoly");
	std::cout << c;
	Emily.signForm(c);
	Nico.executeForm(c);
}

void test_invalid() {
	Bureaucrat Emily("Emily", 150);
	ShrubberyCreationForm a;
	RobotomyRequestForm b;
	PresidentialPardonForm c;	print_line();

	try { Emily.signForm(a); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	print_line();
	try { Emily.executeForm(a); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	print_line();
	try { Emily.signForm(b); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	print_line();
	try { Emily.signForm(c); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

int main(void)
{
	print_line();
	
	t("* Valid signs and executions *");	test_valid();	print_line();
	t("* Invalids signs and executions *");	test_invalid();	print_line();

}