#pragma once
#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <math.h>

class Fixed
{
	private:

		int					_rawBits;
		static const int 	_fractional = 8;
		const float	_powerOfFractioal;

		

	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &src);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);
		Fixed &operator<(Fixed const &rhs);
		Fixed &operator>(Fixed const &rhs);
		Fixed &operator==(Fixed const &rhs);
		Fixed &operator!=(Fixed const &rhs);
		Fixed &operator<=(Fixed const &rhs);
		Fixed &operator>=(Fixed const &rhs);
		Fixed &operator+(Fixed const &rhs);
		Fixed &operator-(Fixed const &rhs);
		Fixed &operator*(Fixed const &rhs);
		Fixed &operator/(Fixed const &rhs);

		int					getRawBits( void ) const;
		void 				setRawBits( int const raw );

		float 				toFloat( void ) const;
		int 				toInt( void ) const;
};

std::ostream				&operator<<(std::ostream &o, Fixed const &i);

#endif