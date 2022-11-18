#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
	ClapTrap	Josefina("Josefina");
	ScavTrap	Carlinhos("Carlinhos");
	FragTrap	Bill("Bill");
	DiamondTrap	Beatrix_Kiddo("Beatrix_Kiddo");

	std::cout << std::string(42, '-') << std::endl;

	std::cout << Josefina << std::endl;
	std::cout << Carlinhos << std::endl;
	std::cout << Bill << std::endl;
	std::cout << Beatrix_Kiddo;

	std::cout << std::string(42, '-') << std::endl;

	Bill.highFivesGuys();
	Beatrix_Kiddo.attack("Bill");
	Bill.takeDamage(Beatrix_Kiddo.getDMG());
	std::cout << Bill;

	std::cout << std::string(42, '-') << std::endl;
}
