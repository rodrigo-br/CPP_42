#pragma once
#ifndef AANIMAL_H
# define AANIMAL_H

#include "Brain.hpp"

class AAnimal
{
	protected:
		virtual void			makeSound() const = 0;
};

#endif