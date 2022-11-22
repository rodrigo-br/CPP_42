#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void clean_the_floor() {
	for (int i = 0; i < 10; i++) {
		if (Character::floor[i]) {
			delete Character::floor[i];
		}
	}
}

void print_adress(Character **a, Character **b, MateriaSource **c) {
	print_line();
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	std::cout << *c << std::endl;
}

void destructors(Character **a, Character **b) {
	print_line();
	delete *a;
	delete *b;
}

void materia_source(Character *a, Character *b, MateriaSource *ms) {
	ms->learnMateria(new Cure());
	a->equip(ms->createMateria("cure"));
	a->use(0, *b);
}

int main (void)
{
	print_line(); t("Pdf test: "); print_line(); {
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		clean_the_floor();
	} print_line();
	
	Character		*Robertinho = new Character("Robertinho");
	Character		*Josefina = new Character("Josefina");
	MateriaSource	*ms = new MateriaSource();
	t("Adress: ");		print_adress(&Robertinho, &Josefina, &ms); 	print_line();
	t("Materia Src: ");	materia_source(Robertinho, Josefina, ms);print_line();
	destructors(&Robertinho, &Josefina);
	// t("Assign Ctor");	test_assignment_deep_cpy();				print_line();
	// t("Cpy Ctor");		test_cpy_constr_deep_cpy();				print_line();
}
