#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		AForm		*_makeShrubberyCreationForm(std::string target);
		AForm		*_makeRobotomyRequestForm(std::string target);
		AForm		*_makePresidentialPardonForm(std::string target);

	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		AForm		*makeForm(std::string name, std::string target);
		Intern		&operator=(Intern const &src);
};

#endif