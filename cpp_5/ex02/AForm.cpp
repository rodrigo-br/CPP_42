#include "AForm.hpp"

AForm::AForm() :
	_name("Boring AForm"), _signed(false), _gradeToSign(69), _gradeToExecute(42) {
}

AForm::AForm(AForm const &src) :
	_name("Boring AForm"), _signed(false), _gradeToSign(69), _gradeToExecute(42) {
	*this = src;
}

AForm::AForm(std::string name, short gradeToSign, short gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec) {
}

AForm::~AForm() {
}

AForm	&AForm::operator=(AForm const &src) {
	this->_signed = src.isSigned();
	const_cast<std::string &>(this->_name) = src.getName();
	const_cast<short &>(this->_gradeToSign) = src.getGradeToSign();
	const_cast<short &>(this->_gradeToExecute) = src.getGradeToExecute();
	return *this;
}

std::string	AForm::getName() const { return this->_name; }

bool	AForm::isSigned() const { return this->_signed; }

short	AForm::getGradeToSign() const { return this->_gradeToSign; }

short	AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void	AForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->getGradeToSign()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because not enough grade." << std::endl;
		throw AForm::GradeTooLowException(); 
	}
	else if (this->isSigned()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
		throw AForm::AFormAlreadySigned();
	}
	else { 
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

void	AForm::beExecuted(Bureaucrat const &b) {
	if (!this->isSigned()) {
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because it isn't signed yet." << std::endl;
		throw AForm::NotSignedException();
	}
	else if (b.getGrade() > this->getGradeToExecute()) {
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because not enough grade." << std::endl;
		throw AForm::GradeTooLowException(); 
	}
	else { 
		std::cout << b.getName() << " executed " << this->getName() << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

const char *AForm::AFormAlreadySigned::what() const throw() {
	return "AForm already signed";
}

const char *AForm::NotSignedException::what() const throw() {
	return "AForm not signed yet";
}

void	AForm::setSigned() {
	this->_signed = true;
}

void	AForm::setName(std::string name) {
	const_cast<std::string &>(this->_name) = name;
}

void	AForm::	setGradeToSign(short n) {
	const_cast<short &>(this->_gradeToSign) = n;
}

void	AForm::	setGradeToExecute(short n) {
	const_cast<short &>(this->_gradeToExecute) = n;
}


std::ostream	&operator<<(std::ostream &o, AForm const &f) {
	o << "AForm name = " << f.getName() << "\nRequired Grade to Sign = " << f.getGradeToSign() <<
	"\nRequired Grade to Execute = " << f.getGradeToExecute() << "\nStatus = " <<
	(f.isSigned() ? "Signed" : "Not Signed") << std::endl;
	return o;
}