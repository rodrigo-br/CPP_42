#pragma once
#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	protected:
		std::string		type;
		
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		~WrongCat();

	WrongCat	&operator=(WrongCat const &src);

	void			makeSound() const;
	std::string		getType() 	const;
};

std::ostream	&operator<<(std::ostream &o, WrongCat const &value);

#endif