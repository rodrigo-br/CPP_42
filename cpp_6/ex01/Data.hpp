#ifndef DATA_H
# define DATA_H

#include <string>
#include <iostream>
#include <stdint.h>

class Data
{
	private:
		std::string	_info;

	public:
		Data();
		Data(Data const &src);
		~Data();
		std::string	getInfo() const;

		Data &operator=(Data const &src);
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif