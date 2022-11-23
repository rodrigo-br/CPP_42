#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const short			_gradeToSign;
		const short			_gradeToExecute;

	protected:
		void				setName(std::string name);
		void				setSigned();
		void				setGradeToSign(short n);
		void				setGradeToExecute(short n);

	public:

		AForm();
		AForm(AForm const &src);
		AForm(std::string name, short gradeToSign, short gradeToExec);
		virtual ~AForm();

		AForm	&operator=(AForm const &src);

		std::string			getName() const;
		bool				isSigned() const;
		short				getGradeToSign() const;
		short				getGradeToExecute() const;

		virtual void		beSigned(Bureaucrat const &b) = 0;
		virtual void		beExecuted(Bureaucrat const &b) = 0;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class AFormAlreadySigned : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &f);



#endif