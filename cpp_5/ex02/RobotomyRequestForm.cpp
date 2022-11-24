#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm::AForm("RobotomyRequestForm", 72, 45), _target("No one") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
	this->setName(src.getName());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->_target) = src.getTarget();
	return *this;
}

void	RobotomyRequestForm::beSigned(Bureaucrat const &b) {
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

void	RobotomyRequestForm::execute(Bureaucrat const &b) const {
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
		this->robotomize();
	}
}

void RobotomyRequestForm::robotomize() const {
	srand (time(NULL));
	std::cout << "ZZzzZ B BZVBzzb Zz ZBGZ VzVZ vbZVCDzvcbaCZBZVZVZZ" << std::endl;
	if (rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
		return ;
	}
	std::cout << "robotomy failed" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}