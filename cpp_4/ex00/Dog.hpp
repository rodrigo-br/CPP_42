#pragma once
#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	private:

	protected:
		std::string		type;
		
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

	Dog	&operator=(Dog const &src);

	void			makeSound() const;
	std::string		getType()	const;
};

std::ostream	&operator<<(std::ostream &o, Dog const &value);

#endif