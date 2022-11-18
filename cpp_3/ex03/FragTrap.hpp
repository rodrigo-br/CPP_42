#pragma once
#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

		static std::string		const	_type;

	protected:
		void	updateFrag(int hp, int ep, int dmg);

	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap();

		FragTrap &operator=(FragTrap const &rhs);

		void highFivesGuys(void);
};

#endif