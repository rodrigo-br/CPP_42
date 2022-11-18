#pragma once
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		static std::string const	_type;

	protected:
		std::string	const	_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDmg;

	public:
		ClapTrap();
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap &operator=(ClapTrap const &rhs);

		virtual void attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		std::string getName() const;
		int			getHP() const;
		int			getEP() const;
		int			getDMG() const;
		void		setHP(unsigned int value);
		void		setEP(unsigned int value);
		void		setDMG(unsigned int value);
};

std::ostream	&operator<<(std::ostream &o, ClapTrap const &value);

#endif