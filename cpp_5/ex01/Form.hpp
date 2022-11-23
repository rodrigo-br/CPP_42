#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const short			_gradeToSign;
		const short			_gradeToExecute;

	public:

		Form();
		Form(Form const &src);
		Form(std::string name, short gradeToSign, short gradeToExec);
		~Form();

		Form	&operator=(Form const &src);

		std::string	getName() const;
		bool		isSigned() const;
		short		getGradeToSign() const;
		short		getGradeToExecute() const;
		void		beSigned(Bureaucrat const &b);
		void		beExecuted(Bureaucrat const &b);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &f);



#endif