#include "Data.hpp"

Data::Data() :  _info("cavalinho") {}

Data::~Data() {}

Data::Data(Data const &src) { *this = src; }

Data &Data::operator=(Data const &src) {
	this->_info = src.getInfo();
	return *this;
}

std::string Data::getInfo() const { return this->_info; }