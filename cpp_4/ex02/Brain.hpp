#ifndef BRAIN_H
# define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
	protected:
		std::string		ideas[100];

	public:
		Brain();
		~Brain();
		Brain(Brain const &src);

		void	operator=(Brain const &src);

		std::string		getIdea(int index) const;
		void			setIdea(std::string idea, int index);
};

#endif