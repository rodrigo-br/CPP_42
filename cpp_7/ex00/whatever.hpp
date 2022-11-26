#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template <typename T>
T const	&max(T const &x, T const &y) {
	return (x > y ? x : y);
}

template <typename T>
T const	&min(T const &x, T const &y) {
	return (x < y ? x : y);
}

template <typename T>
void	swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}


#endif 