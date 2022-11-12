#include "Zombie.hpp"

int main (void)
{
	int n_of_zombies = 5;
	Zombie *horde = zombieHorde(n_of_zombies, "cavalinho");
	for (int i = 0; i < n_of_zombies; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}