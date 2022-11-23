#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Travolta"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, short grade) {
	if (grade < 1) { throw Bureaucrat::GradeTooHighException(); }
	else if (grade > 150) { throw Bureaucrat::GradeTooLowException(); }
	else {
		const_cast<std::string &>(this->_name) = name;
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(short grade) : _name("John Travolta"), _grade(grade) {
	if (grade < 1) { throw Bureaucrat::GradeTooHighException(); }
	else if (grade > 150) { throw Bureaucrat::GradeTooLowException(); }
	else { this->_grade = grade; }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src) {
	const_cast<std::string &>(this->_name) = src.getName();
	this->_grade = src.getGrade();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}

std::string	Bureaucrat::getName() const { return this->_name; }

short	Bureaucrat::getGrade() const { return this->_grade; }

void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1) { throw Bureaucrat::GradeTooHighException(); }
	this->_grade--; 
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150 ) { throw Bureaucrat::GradeTooLowException(); }
	this->_grade++;
}

void	Bureaucrat::signForm(Form &f) {
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(Form &f) {
	f.beExecuted(*this);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}
