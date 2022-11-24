#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string		_target;

		void					grantPardon() const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

		std::string	getTarget() const;
		void		beSigned(Bureaucrat const &b);
		void		execute(Bureaucrat const &b) const;
};

#endif
