#pragma once
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cctype>
# include <cstring>
# include <string>
# include <ios>
# include <iostream>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	public:

		Contact	contacts[8];

		PhoneBook();
		~PhoneBook();

		void	init_phonebook(void);

	private:

		static int	_n_of_contacts;
		static int	_oldest;

		int			_check_options(std::string option);
		int			_check_number(std::string n);
		void		_add_contact();
		void		_list_contacts();
		void		_update_contact();
		std::string _check_trunc(std::string str) const;
		static int	_get_n_of_contacts();
		int			_get_oldest() const;
		int			_update_oldest();
};

#endif