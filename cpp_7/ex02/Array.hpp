#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template<typename T>class Array
{
	private:
		T		*_array;
		size_t	_size;

	public:

		Array<T>() : _array(NULL), _size(0) {};

		Array<T>(unsigned int n) : _size(n) {
			_array = new T[n];
		};

		Array<T>(Array<T> const &src) {
			*this = src;
		};

		~Array<T>() {
			if (_array)
				delete[] _array;
		};

		T	&operator[](unsigned int i) {
			if (i >= 0 && i < _size)
				return _array[i];
			throw WrongIndexException();
		};

		Array<T> &operator=(Array<T> const &src) {
			_size = src.size();
			_array = new T[_size];
			for (unsigned int i=0;i<_size;i++) {
				_array[i] = src._array[i];
			}
			return *this;
		};

		size_t		size() const { return _size; };

		class WrongIndexException : public std::exception {
			public :
				virtual const char *what() const throw() {
					return "Ur doing it wrong\n";
				};
		};

};

#endif