#pragma once
#ifndef HUMANB_H
# define HUMANB_H

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		const		_name;
		Weapon			*			_weapon;

	public:
		HumanB(std::string name);
		~HumanB();

	void 		attack()			const;
	std::string	get_name()			const;
	std::string	get_weapon()		const;
	void		setWeapon(Weapon & weapon);
};


#endif