#include "Zombie.hpp"
# include "utils.hpp"

int main (void)
{
	Zombie *zombie_without_call = newZombie("Cavalinho");
	Zombie *zombie_with_call = randomChump("Carlinhos");

	delete	zombie_without_call;
	delete	zombie_with_call;
	return (0);
}
