#pragma once
#ifndef CAT_H
# define CAT_H

#include "Brain.hpp"
#include "Animal.hpp"

class Brain;

class Cat : public Animal
{
	private:
		Brain			*_brain;

	protected:
		std::string		type;
		
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

	Cat	&operator=(Cat const &src);

	void			makeSound() const;
	std::string		getType() 	const;
	Brain			useBrain();
};

std::ostream	&operator<<(std::ostream &o, Cat const &value);

#endif