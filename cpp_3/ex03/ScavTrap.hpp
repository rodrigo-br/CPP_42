#pragma once
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:

		static std::string		const	_type;

	protected:
		void	updateScav(int hp, int ep, int dmg);

	public:
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &rhs);

		void attack(const std::string& target);//override
		void guardGate();
	
};

#endif