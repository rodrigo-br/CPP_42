#pragma once
#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:

		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;

		Contact();
		~Contact();
};

#endif