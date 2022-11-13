#include "Harl.hpp"

Harl::Harl() {
	this->map[0] = "DEBUG";
	this->map[1] = "INFO";
	this->map[2] = "WARNING";
	this->map[3] = "ERROR";
	std::cout << "Harl Constructor Called" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl Destructor Called" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void 	Harl::complain( std::string level ) {
	void (Harl::*funcs[4])() = { 
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(map[i]) == 0) {
			std::cout << map[i] << std::endl;
			(this->*funcs[i])();
			break ;
		}
	}
}
