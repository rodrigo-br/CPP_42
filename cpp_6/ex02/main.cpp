#include "Base.hpp"
#include <unistd.h>

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg, short i) {
	std::cout << "\t\t" << msg << i << std::endl;
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		print_line(); t("Teste ", i);
		Base *random_derivated_pointer = generate();
		identify(random_derivated_pointer);
		
		Base &random_derivated_reference = *random_derivated_pointer;
		identify(random_derivated_reference);

		delete random_derivated_pointer;
		usleep(666);
	}
}
