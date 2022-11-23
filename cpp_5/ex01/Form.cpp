#include "Form.hpp"

Form::Form() :
	_name("Boring Form"), _signed(false), _gradeToSign(69), _gradeToExecute(42) {
}

Form::Form(Form const &src) :
	_name("Boring Form"), _signed(false), _gradeToSign(69), _gradeToExecute(42) {
	*this = src;
}

Form::Form(std::string name, short gradeToSign, short gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec) {
}

Form::~Form() {
}

Form	&Form::operator=(Form const &src) {
	this->_signed = src.isSigned();
	const_cast<std::string &>(this->_name) = src.getName();
	const_cast<short &>(this->_gradeToSign) = src.getGradeToSign();
	const_cast<short &>(this->_gradeToExecute) = src.getGradeToExecute();
	return *this;
}

std::string	Form::getName() const { return this->_name; }

bool	Form::isSigned() const { return this->_signed; }

short	Form::getGradeToSign() const { return this->_gradeToSign; }

short	Form::getGradeToExecute() const { return this->_gradeToExecute; }

void	Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->getGradeToSign()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because not enough grade." << std::endl;
		throw Form::GradeTooLowException(); 
	}
	else if (this->isSigned()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
		throw Form::FormAlreadySigned();
	}
	else { 
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

void	Form::beExecuted(Bureaucrat const &b) {
	if (!this->isSigned()) {
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet." << std::endl;
		throw Form::NotSignedException();
	}
	else if (b.getGrade() > this->getGradeToExecute()) {
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because not enough grade." << std::endl;
		throw Form::GradeTooLowException(); 
	}
	else { 
		std::cout << b.getName() << " executed " << this->getName() << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

const char *Form::FormAlreadySigned::what() const throw() {
	return "Form already signed";
}

const char *Form::NotSignedException::what() const throw() {
	return "Form not signed yet";
}

std::ostream	&operator<<(std::ostream &o, Form const &f) {
	o << "Form name = " << f.getName() << "\nRequired Grade to Sign = " << f.getGradeToSign() <<
	"\nRequired Grade to Execute = " << f.getGradeToExecute() << "\nStatus = " <<
	(f.isSigned() ? "Signed" : "Not Signed") << std::endl;
	return o;
}