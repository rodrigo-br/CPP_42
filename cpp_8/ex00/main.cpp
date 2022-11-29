#include "easyfind.hpp"

int main (void)
{
	std::vector<int>::iterator	it;
	std::vector<int>			v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	it = easyfind(v, 5);
	std::cout << *it << std::endl;

	try {
		easyfind(v, -1);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}