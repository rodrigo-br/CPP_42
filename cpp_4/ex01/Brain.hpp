#pragma once
#ifndef BRAIN_H
# define BRAIN_H

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

class Brain
{
	protected:
		std::string		ideas[100];

	public:

		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain	&operator=(Brain const &src);
		std::string	getIdea(int i);
};


#endif