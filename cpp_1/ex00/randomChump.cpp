#include "Zombie.hpp"

Zombie* randomChump( std::string name )
{
	Zombie	*new_zombie = new Zombie;

	new_zombie->choose_name(name);
	new_zombie->announce();
	return new_zombie;
}