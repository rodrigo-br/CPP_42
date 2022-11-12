#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();

		void announce();
		void choose_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif