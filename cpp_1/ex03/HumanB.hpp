#pragma once
#ifndef HUMANB_H
# define HUMANB_H

# include <string>
# include <iostream>

class HumanB
{
	private:
		std::string	_Weapon;
		std::string	_Name;

	public:
		HumanB();
		~HumanB();
	void attack();
};


#endif