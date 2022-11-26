#ifndef ITER_H
# define ITER_H

#include <iostream>

template<typename T>
void iter(T *array, size_t lenght, void(*f)(T &)) {
	for (size_t i = 0; i < lenght; i++) {
		f(array[i]);
	}
};

template<typename T>
void print_element(T &i) {
	std::cout << i << std::endl;
};

template<typename T>
void sum_element(T &i) {
	std::cout << (T)(i + 1) << std::endl;
};

void sum_element(std::string &i) {
	(void)i;
	std::cout << "can't sum string :(" << std::endl;
};

#endif 