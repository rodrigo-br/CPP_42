#ifndef CONVERT_H
# define CONVERT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <limits>

class Convert
{
	private:
		std::string		_str;
		unsigned char	_Cchar;
		long			_Cint;
		float			_Cfloat;
		double			_Cdouble;
		bool			_Cinvalid;
		bool			_Cpseudo;

	public:

		enum literalType {
			ISINVALID, ISCHAR, ISINT, ISFLOAT, ISDOUBLE
		};
						Convert();
						Convert(Convert const &src);
						Convert(std::string str);
						~Convert();

		Convert			&operator=(Convert const &src);
		unsigned char	getChar() const;
		long			getInt() const;
		float			getFloat() const;
		double			getDouble() const;
		bool			getInvalid() const;
		bool			getPseudo() const;
		std::string		getStr() const;
		literalType		identifyType(std::string str);
		bool			isChar(std::string str);
		bool			isInt(std::string str);
		bool			isFloat(std::string str);
		bool			isDouble(std::string str);
		void			selectConvert(literalType type);
		void			convertChar(char *str);
		void			convertInt(char *str);
		void			convertFloat(char *str);
		void			convertDouble(char *str);
		void			isInvalid(char *str);
		bool			isPseudo();
		std::ostream	&handlePseudo(std::ostream &o, Convert const &c);
};

std::ostream	&operator<<(std::ostream &o, Convert const &c);

#endif