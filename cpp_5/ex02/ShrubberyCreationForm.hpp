#ifndef SHRUBERRYCREATIONFORM_H
# define SHRUBERRYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		void		beSigned(Bureaucrat const &b);
		void		beExecuted(Bureaucrat const &b);
};

#endif