#include "Dog.hpp"
#include "Cat.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

void constructors(const Cat **a, const Cat **b) {
	print_line();
	*a = new Cat();
	*b = new Cat();
}

void print_adress(const Cat **a, const Cat **b) {
	print_line();
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
}

void destructors(const Cat **a, const Cat **b) {
	delete *a;
	delete *b;
}

void test_brain(const Cat **a) {
	print_line();
	std::cout << (*a)->getBrain()->getIdea(1) << std::endl;

	(*a)->getBrain()->setIdea("Write a bestseller book", 1);

	std::cout << (*a)->getBrain()->getIdea(1) << std::endl;
}

void test_assignment_deep_cpy() {
	print_line();
	Cat a;
	Cat b;								print_line();

	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;		print_line();

	delete a.getBrain();
	a = b;

	a.getBrain()->setIdea("Write a bestseller book", 1);
	std::cout << a.getBrain()->getIdea(1) << std::endl;
	std::cout << b.getBrain()->getIdea(1) << std::endl;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;		print_line();
}

void test_cpy_constr_deep_cpy() {
	print_line();
	const Cat *a;
	const Cat *b;

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
	print_line();
	const Cat *cat;
	const Cat *schrodinger;
	//AAnimal a; // uncomment me to raise an error D:

	t("Ctors");			constructors(&cat, &schrodinger); 	print_line();
	t("Adress: ");		print_adress(&cat, &schrodinger); 	print_line();
	t("Brain");			test_brain(&cat); 					print_line();
	t("Assign Ctor");	test_assignment_deep_cpy();			print_line();
	t("Cpy Ctor");		test_cpy_constr_deep_cpy();			print_line();
	t("Dtors");			destructors(&cat, &schrodinger); 	print_line();
}
