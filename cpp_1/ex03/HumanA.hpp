#pragma once
#ifndef HUMANA_H
# define HUMANA_H

# include <string>
# include <iostream>

class HumanA
{
	private:
		std::string	_weapon;
		std::string	_name;

	public:
		HumanA(std::string name);
		~HumanA();
	void attack();
};

#endif