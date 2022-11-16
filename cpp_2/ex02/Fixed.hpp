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
		const float			_powerOfFractional;

	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &src);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);
		bool operator<(Fixed const &rhs) const;
		bool operator>(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);
		Fixed &operator++();
		Fixed operator++(int);

		int					getRawBits( void ) const;
		void 				setRawBits( int const raw );

		float 				toFloat( void ) const;
		int 				toInt( void ) const;

		static Fixed		&max(Fixed &firt, Fixed &right);
		static const Fixed	&max(Fixed const &firt, Fixed const &right);
};

std::ostream				&operator<<(std::ostream &o, Fixed const &value);

#endif