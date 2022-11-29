#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

class notFoundException : public std::exception {
	virtual const char *what() const throw() {
		return "not found\n";
	}
};

template<typename T>
typename T::iterator	easyfind(T &haystack, int needle) {
	typename T::iterator _it;
	_it = find(haystack.begin(), haystack.end(), needle);
	if (_it == haystack.end())
		throw notFoundException();
	return _it;
};



#endif