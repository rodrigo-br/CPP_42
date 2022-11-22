#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

#include <iostream>

/*
	Since the characters drop their inventory in the floor upon destruction,
	Be sure that you clean the floor AFTER the last Character destructor call
*/
void clean_the_floor() {
	for (int i = 0; i < 10; i++) {
		if (Character::floor[i]) {
			delete Character::floor[i];
		}
	}
}

int main (void)
{
	Character JohnDoe("Roberto");
	Character Josephina("Josephina");

	JohnDoe.equip(JohnDoe.getMateriaFromFloor(6));
	JohnDoe.use(0, Josephina);
	JohnDoe.equip(JohnDoe.getMateriaFromFloor(6));
	JohnDoe.equip(JohnDoe.getMateriaFromFloor(4));
	JohnDoe.use(0, Josephina);
	JohnDoe.use(1, Josephina);

	JohnDoe.~Character();
	Josephina.~Character();
	clean_the_floor();
	return 0;
}
