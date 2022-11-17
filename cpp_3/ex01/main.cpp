#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap	Josefina("Josefina");
	ScavTrap	Carlinhos("Carlinhos");
	ScavTrap	Iracilda("Iracilda");

	std::cout << std::string(42, '-') << std::endl;

	std::cout << Josefina;
	std::cout << Carlinhos;
	std::cout << Iracilda;

	std::cout << std::string(42, '-') << std::endl;

	Iracilda.attack("Carlinhos");
	Carlinhos.takeDamage(Iracilda.getDMG());
	std::cout << Carlinhos;
	std::cout << Iracilda;

	std::cout << std::string(42, '-') << std::endl;

	Carlinhos.beRepaired(20);
	Carlinhos.guardGate();
	std::cout << Carlinhos;

	std::cout << std::string(42, '-') << std::endl;
}
