#pragma once
#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	protected:
		std::string		type;
		
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

	Cat	&operator=(Cat const &src);

	void			makeSound() const;
	std::string		getType() 	const;
};

std::ostream	&operator<<(std::ostream &o, Cat const &value);

#endif