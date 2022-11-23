#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}


int main(void)
{
	print_line();
	AForm *a = new ShrubberyCreationForm();

	std::cout << a << std::endl;
	std::cout << *a;
	// t("* Copys *");		();	print_line();
	// t("* Sign Form *");	();	print_line();
	// t("* Invalids *");	();	print_line();
}