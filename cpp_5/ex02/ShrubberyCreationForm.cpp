#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm::AForm("ShrubberyCreationForm", 145, 137), _target("No_name") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
 AForm::AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	this->setName(src.getName());
	this->setGradeToSign(src.getGradeToSign());
	this->setGradeToExecute(src.getGradeToExecute());
	const_cast<std::string &>(this->_target) = src.getTarget();
	return *this;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat const &b) {
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

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const {
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
		this->createFile();
	}
}

void ShrubberyCreationForm::createFile() const {
	std::ofstream	ofs((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
ofs << "											 .			\n" <<
"											  .         ;  		\n" <<
"				 .              .              ;%     ;;   		\n" <<
"				   ,           ,                :;%  %;   		\n" <<
"					:         ;                   :;%;'     .,  \n" << 
"		   ,.        %;     %;            ;        %;'    ,;	\n" <<
"			 ;       ;%;  %%;        ,     %;    ;%;    ,%'		\n" <<
"			  %;       %;%;      ,  ;       %;  ;%;   ,%;' 		\n" <<
"			   ;%;      %;        ;%;        % ;%;  ,%;'		\n" <<
"				`%;.     ;%;     %;'         `;%%;.%;'			\n" <<
"				 `:;%.    ;%%. %@;        %; ;@%;%'				\n" <<
"					`:%;.  :;bd%;          %;@%;'				\n" <<
"					  `@%:.  :;%.         ;@@%;'   				\n" <<
"						`@%.  `;@%.      ;@@%;       			\n" <<  
"						  `@%%. `@%%    ;@@%;        			\n" <<
"							;@%. :@%%  %@@%;       				\n" <<
"							  %@bd%%%bd%%:;     				\n" <<
"								#@%%%%%:;;						\n" <<
"								%@@%%%::;						\n" <<
"								%@@@%(o);  . '   				\n" <<      
"								%@@@o%;:(.,'      				\n" <<   
"							`.. %@@@o%::;         				\n" <<
"							   `)@@@o%::;         				\n" <<
"								%@@(o)::;        				\n" <<
"							   .%@@@@%::;         				\n" <<
"							   ;%@@@@%::;.        				\n" <<  
"							  ;%@@@@%%:;;;. 					\n" <<
"						  ...;%@@@@@%%:;;;;,..					\n" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}