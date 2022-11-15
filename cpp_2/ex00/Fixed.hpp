#pragma once
#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int 	_fractional = 8;

	public:

		Fixed();
		Fixed(Fixed const &src);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);

		int					getRawBits( void ) const;
		void 				setRawBits( int const raw );
};

#endif