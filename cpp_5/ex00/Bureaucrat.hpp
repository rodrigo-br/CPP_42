#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>

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

		class exceptionLow : public std::exception
		{
			virtual const char *what() const throw();
		};
		class exceptionHigh : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b);

#endif