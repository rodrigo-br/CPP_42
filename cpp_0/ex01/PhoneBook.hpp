#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cctype>
# include <cstring>
# include <string>
# include <ios>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:

		Contact	contacts[8];

		PhoneBook();
		~PhoneBook();

		void	init_phonebook(void);

	private:

		int			_check_options(std::string option);
		int			_check_number(std::string n);
		void		_add_contact();
		void		_list_contacts();
		void		_update_contact();
		std::string _check_trunc(std::string str);
		static int	_get_n_of_contacts();
		static int	_n_of_contacts;
		static int	_oldest;
		int			_get_oldest();
		int			_update_oldest();
};

#endif