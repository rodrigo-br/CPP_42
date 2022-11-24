#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string		_target;

		void					robotomize() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		std::string	getTarget() const;
		void		beSigned(Bureaucrat const &b);
		void		execute(Bureaucrat const &b) const;
};

#endif