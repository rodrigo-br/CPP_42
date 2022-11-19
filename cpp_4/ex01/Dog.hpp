#pragma once
#ifndef DOG_H
# define DOG_H

#include "Brain.hpp"
#include "Animal.hpp"

class Brain;

class Dog : public Animal
{
	private:
		Brain			*_brain;

	protected:
		std::string		type;
		
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

	Dog	&operator=(Dog const &src);

	void			makeSound() const;
	std::string		getType()	const;
	Brain			useBrain();
};

std::ostream	&operator<<(std::ostream &o, Dog const &value);

#endif