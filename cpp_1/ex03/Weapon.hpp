#pragma once
#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon();
		~Weapon();

	std::string getType();
	void		setType(std::string);
};


#endif