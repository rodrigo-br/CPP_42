#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Travolta"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, short grade) {
	if (grade < 1) { throw Bureaucrat::exceptionHigh(); }
	else if (grade > 150) { throw Bureaucrat::exceptionLow(); }
	else {
		const_cast<std::string &>(this->_name) = name;
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(short grade) : _name("John Travolta"), _grade(grade) {
	if (grade < 1) { throw Bureaucrat::exceptionHigh(); }
	else if (grade > 150) { throw Bureaucrat::exceptionLow(); }
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
	if (this->_grade == 1) { throw Bureaucrat::exceptionHigh(); }
	this->_grade--; 
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150 ) { throw Bureaucrat::exceptionLow(); }
	this->_grade++;
}

const char* Bureaucrat::exceptionLow::what() const throw() {
	return "Bureaucrat grade too low";
}

const char* Bureaucrat::exceptionHigh::what() const throw() {
	return "Bureaucrat grade too high";
}