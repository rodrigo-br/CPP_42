#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		short				_grade;

	public:

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(short grade);
		Bureaucrat(std::string name);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(std::string name, short grade);

		Bureaucrat &operator=(Bureaucrat const &src);

		std::string getName() const;
		short		getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &f);
		void		executeForm(AForm &f);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b);

#endif