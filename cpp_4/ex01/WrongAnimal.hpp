#pragma once
#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
	private:

	protected:
		std::string		type;
		
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal();

	WrongAnimal	&operator=(WrongAnimal const &src);

	void			makeSound() const;
	std::string		getType() 	const;
};

std::ostream	&operator<<(std::ostream &o, WrongAnimal const &value);

#endif