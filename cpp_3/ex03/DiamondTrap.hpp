#pragma once
#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:	
		std::string 		_name;
		static std::string	const	_type;

		void	updateDiamond(int hp, int ep, int dmg);

	public:

		DiamondTrap();
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap const &rhs);

		std::string getName() const;
		void whoAmI();
};

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &value);

#endif