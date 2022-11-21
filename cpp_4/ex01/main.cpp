#include "Dog.hpp"
#include "Cat.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void constructors(Cat **a, Cat **b) {
	*a = new Cat();
	*b = new Cat();
}

void print_adress(Cat **a, Cat **b) {
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
}

void test_simple_polymorphism() {
	Animal *yet_to_be_a_cat;

	yet_to_be_a_cat = new Cat();

	yet_to_be_a_cat->makeSound();
	std::cout << "My type is: " << yet_to_be_a_cat->getType() << std::endl;

	delete yet_to_be_a_cat;
}

void destructors(Cat **a, Cat **b) {
	delete *a;
	delete *b;
}

void test_brain(Cat **a) {
	std::cout << (*a)->getBrain()->getIdea(1) << std::endl;

	(*a)->getBrain()->setIdea("Write a bestseller book", 1);

	std::cout << (*a)->getBrain()->getIdea(1) << std::endl;
}

void test_assignment_deep_cpy() {
	Cat a;
	Cat b;								print_line();

	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;		print_line();

	a.~Cat();
	a = b;

	a.getBrain()->setIdea("Write a bestseller book", 1);
	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;		print_line();
}

void test_cpy_constr_deep_cpy() {
	Cat *a;
	Cat *b;

	a = new Cat();
	b = new Cat(*a);					print_line();

	std::cout << "endereço de a = " << a << std::endl;
	std::cout << "endereço de b = " << b << std::endl;
	std::cout << "endereço brain de a = " << a->getBrain() << std::endl;
	std::cout << "endereço brain de b = " << b->getBrain() << std::endl;

	print_line(); destructors(&a, &b);
}

int main(void)
{
	Cat *cat;
	Cat *schrodinger;

	t("Ctors");			constructors(&cat, &schrodinger); 	print_line();
	t("Adress: ");		print_adress(&cat, &schrodinger); 	print_line();
	t("PolyM");			test_simple_polymorphism(); 		print_line();
	t("Brain");			test_brain(&cat); 					print_line();
	t("Assign Ctor");	test_assignment_deep_cpy();			print_line();
	t("Cpy Ctor");		test_cpy_constr_deep_cpy();			print_line();
	t("Dtors");			destructors(&cat, &schrodinger); 	print_line();
}
