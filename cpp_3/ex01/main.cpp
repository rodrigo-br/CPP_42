#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap	Josefina("Josefina");
	ClapTrap	Carlinhos("Carlinhos");

	std::cout << Josefina;
	Josefina.attack("Carlinhos");
	Carlinhos.takeDamage(Josefina.getDMG());
	std::cout << Josefina;
	Josefina.beRepaired(10);
	std::cout << Josefina;
}
