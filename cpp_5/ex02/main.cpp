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

int main(void)
{
	print_line();
	Bureaucrat	nicolauvsk("Nicolauvsk", 1);
	PresidentialPardonForm a("Emily");

	nicolauvsk.signForm(a);
	nicolauvsk.executeForm(a);
	// t("* Copys *");		();	print_line();
	// t("* Sign Form *");	();	print_line();
	// t("* Invalids *");	();	print_line();
}