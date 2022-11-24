#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern::~Intern() {
}

Intern	&Intern::operator=(Intern const &src) {
	(void)src;
	return *this;
}

AForm	*Intern::_makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::_makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::_makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string map[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	AForm *(Intern::*func[3])(std::string target) = {&Intern::_makeShrubberyCreationForm,
	&Intern::_makeRobotomyRequestForm, &Intern::_makePresidentialPardonForm};
	
	for (int i = 0; i < 3; i++) {
		if (name.compare(map[i]) == 0) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*func[i])(target);
		}
	}
	std::cout << "EEEEEEEEEEERRRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
	return (NULL);
}