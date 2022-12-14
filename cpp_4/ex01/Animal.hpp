#pragma once
#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	private:

	protected:
		std::string		type;
		
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();

	Animal	&operator=(Animal const &src);

	virtual void			makeSound() const;
	virtual std::string		getType() 	const;
};

std::ostream	&operator<<(std::ostream &o, Animal const &value);

#endif