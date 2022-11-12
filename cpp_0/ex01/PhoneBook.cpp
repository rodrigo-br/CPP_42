#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook Destructor called" << std::endl;
	return ;
}

int PhoneBook::_check_options(std::string option) {
	if (option.empty()) {
		std::cout << "ADD / SEARCH / EXIT" << std::endl;
		option.clear();
		std::cin.clear();
	}
	else if (option.compare("ADD") == 0) {
		PhoneBook::_add_contact();
	}
	else if (option.compare("SEARCH") == 0) {
		PhoneBook::_list_contacts();
	}
	else if (option.compare("EXIT") == 0) {
		return (0);
	}
	option.clear();
	return (1);
}

void PhoneBook::_add_contact() {
	int	i = this->_get_n_of_contacts();
	if (i == 8)
		i = this->_update_oldest();

	this->contacts[i].index = i + 1;

	std::cout << "First Name" << std::endl;
	std::getline(std::cin >> std::ws, this->contacts[i].first_name);
	std::cout << "Last Name" << std::endl;
	std::getline(std::cin >> std::ws, this->contacts[i].last_name);
	std::cout << "Nickname" << std::endl;
	std::getline(std::cin >> std::ws, this->contacts[i].nickname);
	std::cout << "Phone Number" << std::endl;
	std::getline(std::cin >> std::ws, this->contacts[i].phone_number);
	std::cout << "Darkest Secret" << std::endl;
	std::getline(std::cin >> std::ws, this->contacts[i].darkest_secret);
	if (std::cin.fail()) {
		std::cout << "Oh no, you have destroyed us!" << std::endl;
		this->~PhoneBook();
		exit(0);
	}
	else if (_check_number(this->contacts[i].phone_number)) {
		return ;
	}
	this->_update_contact();
}

void write_at_right(std::string str, bool pipe) {
	std::cout.width(10); std::cout << std::right << str;
	if (pipe)
		std::cout << "|";
}

void PhoneBook::_list_contacts() {
	int contacts = this->_get_n_of_contacts();
	int	index;

	if (!contacts) {
		std::cout << "This crap is empty" << std::endl;
		return ;
	}
	write_at_right("Index", true);
	write_at_right("First Name", true);
	write_at_right("Last Name", true);
	write_at_right("Nickname", false);
	std::cout << std::endl;
	for (int i = 0; i < contacts; i++) {
		write_at_right(std::to_string(this->contacts[i].index), true);
		write_at_right(_check_trunc(this->contacts[i].first_name), true);
		write_at_right(_check_trunc(this->contacts[i].last_name), true);
		write_at_right(_check_trunc(this->contacts[i].nickname), false);
		std::cout << std::endl;
	}
	std::cout << "Choose an index" << std::endl;
	std::cin.clear();
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > contacts) {
		std::cin.clear();
		std::cout << "Damn, u r dumb" << std::endl;
		return ;
	}
	index--;
	std::cout << "Index: "	<< this->contacts[index].index <<			std::endl <<
		"First Name: "		<< this->contacts[index].first_name <<		std::endl <<
		"Last Name: "		<< this->contacts[index].last_name <<		std::endl <<
		"Nickname: "		<< this->contacts[index].nickname <<		std::endl <<
		"Phone Number: "	<< this->contacts[index].phone_number <<	std::endl <<
		"Darkest Secret: "	<< this->contacts[index].darkest_secret <<	std::endl;
}

void PhoneBook::_update_contact() {
	if (PhoneBook::_get_n_of_contacts() < 8)
		PhoneBook::_n_of_contacts++;
}

int PhoneBook::_get_oldest() const {
	return PhoneBook::_oldest;
}

int PhoneBook::_update_oldest() {
	int	update_index = PhoneBook::_get_oldest();
	PhoneBook::_oldest++;
	return update_index;
}

int PhoneBook::_get_n_of_contacts() {
	return PhoneBook::_n_of_contacts;
}

std::string PhoneBook::_check_trunc(std::string str) const {
	std::string	new_str;

	if (str.length() < 10)
		return (str);
	new_str = str.substr(0, 9);
	new_str += '.';
	return (new_str);
}

int		PhoneBook::_check_number(std::string n) {
	for (int i = 0; i < n.length(); i++) {
		if (std::isalpha(n[i]))
		{
			std::cout << "The number shouldn't have any alphabetical value! DUH!"
				<< std::endl;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	PhoneBook::init_phonebook() {
	std::string	option;

	std::cout << "This is the worst PhoneBook u'll ever see :)" << std::endl;
	option.clear();
	while (this->_check_options(option))
	{
		option.clear();
		std::cin >> option;
		if (std::cin.fail()) {
			std::cout << "Oh no, you have destroyed us!" << std::endl;
			this->~PhoneBook();
			exit(0);
		}
	}
}

int	PhoneBook::_n_of_contacts = 0, PhoneBook::_oldest = 0;
