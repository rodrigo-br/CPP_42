#pragma once
#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	private:

	protected:
		std::string		type;
		
	public:
		Animal();
		Animal(Animal const &src);
		~Animal();

	Animal	&operator=(Animal const &src);

	void			makeSound() const;
	std::string		getType() 	const;
};

std::ostream	&operator<<(std::ostream &o, Animal const &value);

#endif