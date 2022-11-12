#pragma once
#ifndef HUMANA_H
# define HUMANA_H

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		const		_name;
		Weapon			const &		_weapon;

	public:
		HumanA(std::string name, Weapon const &weapon);
		~HumanA();

	void			attack()		const;
	std::string		get_name()		const;
	std::string		get_weapon()	const;
};

#endif