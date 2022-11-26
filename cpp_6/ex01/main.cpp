#include "Data.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t" << msg << std::endl;
}

int main (void)
{
	Data		*data = new Data();
	uintptr_t	serialized_data;
	Data		*deserialized_data; print_line();

	t("Compare data and deserialized_data: ");
	std::cout << (deserialized_data == data) << std::endl;
	print_line(); t("get data info: ");
	std::cout << data->getInfo() << std::endl;
	print_line(); t("Serialize n get serialized_data info");
	serialized_data = serialize(data);
	std::cout << serialized_data << std::endl;
	print_line(); t("deserialize n get deserialized_data info");
	deserialized_data = deserialize(serialized_data);
	std::cout << deserialized_data->getInfo() << std::endl;
	print_line(); t("Compare deserialized_data and data");
	std::cout << (deserialized_data == data) << std::endl;
	print_line();
	delete data;
}