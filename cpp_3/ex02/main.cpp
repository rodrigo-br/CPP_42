#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap	Josefina("Josefina");
	ScavTrap	Carlinhos("Carlinhos");
	FragTrap	Bill("Bill");
	FragTrap	Beatrix_Kiddo("Beatrix_Kiddo");

	std::cout << std::string(42, '-') << std::endl;

	std::cout << Josefina << std::endl;
	std::cout << Carlinhos << std::endl;
	std::cout << Bill << std::endl;
	std::cout << Beatrix_Kiddo;

	std::cout << std::string(42, '-') << std::endl;

	Bill.highFivesGuys();
	Beatrix_Kiddo.attack("Bill");
	Bill.takeDamage(Beatrix_Kiddo.getDMG());
	Bill.attack("Beatrix_Kiddo");
	Beatrix_Kiddo.takeDamage(Bill.getDMG());
	std::cout << Bill;

	Beatrix_Kiddo.highFivesGuys();

	std::cout << std::string(42, '-') << std::endl;
}
