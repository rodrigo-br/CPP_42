#include "Array.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t" << msg << std::endl;
}

template<typename T>
void	print_array(Array<T> a) {
	print_line();
	for (unsigned int i=0;i<a.size();i++) {
		std::cout << a[i] << std::endl;
	}
}

int main(void)
{
	Array<unsigned int> empty;
	print_line();t("Empty array");print_line();
	std::cout << empty.size() << std::endl;

	Array<unsigned int> a(5);
	for (int i=0;i<5;i++) {
		a[i] = i;
	}
	print_line();t("reassign array values");print_array(a);

	Array<unsigned int> copy(a);
	print_line();t("testing copy constructor");print_array(copy);

	Array<unsigned int> assign = Array<unsigned int>(a);
	print_line();t("testing assign OP");print_array(assign);

	a[0] = 11;
	copy[0] = 22;
	assign[0] = 33;
	print_line();t("testing independency");
	print_array(a);print_array(copy);print_array(assign);

	Array<std::string> str(5);
	str[0] = "A";
	str[1] = "Emily";
	str[2] = "é";
	str[3] = "uma";
	str[4] = "cachorra";
	print_line();t("Another type of Array");print_array(str);

	print_line();t("Testing invalid indexes");print_line();
	try {
		std::cout << str[5] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	print_line();
	try {
		std::cout << str[-1] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}