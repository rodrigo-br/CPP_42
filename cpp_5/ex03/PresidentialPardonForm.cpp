#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm::AForm("PresidentialPardonForm", 25, 5), _target("No one") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
	this->setName(src.getName());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->_target) = src.getTarget();
	return *this;
}

void	PresidentialPardonForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->getGradeToSign()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because not enough grade." << std::endl;
		throw AForm::GradeTooLowException(); 
	}
	else if (this->isSigned()) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
		throw AForm::AFormAlreadySigned();
	}
	else { 
		this->setSigned();
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const {
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
		this->grantPardon();
	}
}

void PresidentialPardonForm::grantPardon() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}