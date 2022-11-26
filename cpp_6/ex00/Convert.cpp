#include "Convert.hpp"

Convert::Convert() : _Cinvalid(true) {}

Convert::Convert(std::string str) : _str(str), _Cinvalid(false), _Cpseudo(false) {
	this->selectConvert(this->identifyType(this->_str));
}

Convert::Convert(Convert const &src) { *this = src; }

Convert::~Convert() {}

Convert	&Convert::operator=(Convert const &src) {
	this->_str = src.getStr();
	this->_Cinvalid = src.getInvalid();
	this->_Cpseudo = src.getPseudo();
	return *this;
}

std::string		Convert::getStr() const { return this->_str; }

Convert::literalType	Convert::identifyType(std::string str) {
	return (literalType)(this->isChar(str) * ISCHAR +
						this->isInt(str) * ISINT +
						this->isFloat(str) * ISFLOAT +
						this->isDouble(str) * ISDOUBLE);
}

/*******************************************************************************
**  UTILS -> the next 3 static functions are made to keep the methods simple  **
*******************************************************************************/

static bool	notInSet(std::string set, char c) {
	for (int i = 0; i < static_cast<int>(set.length()); i++) {
		if (set[i] == c) { return false; }
	}
	return true;
}

static bool isDigitOrSet(std::string str, std::string set) {
	for (int i = 0; i < static_cast<int>(str.length()); i++) {
		if (!std::isdigit(str[i]) && notInSet(set, str[i]))
			return false;
	}
	return true;
}

static bool	haveOne(std::string str, char c) {
	short counter = 0;
	for (int i = 0; i < static_cast<int>(str.length()); i++) {
		if (str[i] == c) {
			counter++;
		} 
	}
	return (counter == 1);
}

bool	Convert::isChar(std::string str) {
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool	Convert::isInt(std::string str) {
	return isDigitOrSet(str, "");
}

bool	Convert::isDouble(std::string str) {
	return haveOne(str, '.') && isDigitOrSet(str, ".");
}

bool	Convert::isFloat(std::string str) {
	return (haveOne(str, '.') && haveOne(str, 'f') &&
	str[str.length() - 1] == 'f' &&	isDigitOrSet(str, ".f"));
}

void	Convert::selectConvert(literalType type) {
	void	(Convert::*func[5])(char *str) = {
		&Convert::isInvalid, &Convert::convertChar, &Convert::convertInt,
		&Convert::convertFloat, &Convert::convertDouble
	};
	(this->*func[type])(const_cast<char *>(this->getStr().c_str()));
}

bool	Convert::isPseudo() {
	if (this->_str.compare("-inff") == 0 || this->_str.compare("+inff") == 0||
		this->_str.compare("nanf") == 0 || this->_str.compare("nan") == 0 ||
		this->_str.compare("-inf") == 0 || this->_str.compare("+inf") == 0) {
			this->_Cpseudo = true;
			return true;
		}
	return false;
}

void	Convert::isInvalid(char *str) {
	(void)str;
	if (this->isPseudo())
		return ;
	this->_Cinvalid = true;
	std::cout << "conversion is impossible" << std::endl;
}

void	Convert::convertChar(char *str) {
	this->_Cchar = static_cast<char>(str[0]);
	this->_Cint = static_cast<long>(this->_Cchar);
	this->_Cdouble = static_cast<double>(this->_Cchar);
	this->_Cfloat = static_cast<float>(this->_Cchar);
}

void	Convert::convertInt(char *str) {
	this->_Cint = static_cast<long>(std::atol(str));
	if ((this->_Cint > std::numeric_limits<int>::max() ||
		this->_Cint < std::numeric_limits<int>::min()))
		isInvalid((char *)"cavalinho");
	this->_Cchar = static_cast<char>(this->_Cint);
	this->_Cdouble = static_cast<double>(this->_Cint);
	this->_Cfloat = static_cast<float>(this->_Cint);
}

void	Convert::convertFloat(char *str) {
	this->_Cfloat = static_cast<float>(std::atof(str));
	this->_Cchar = static_cast<char>(this->_Cfloat);
	this->_Cint = static_cast<long>(this->_Cfloat);
	this->_Cdouble = static_cast<double>(this->_Cfloat);
}

void	Convert::convertDouble(char *str) {
	this->_Cdouble = static_cast<double>(std::strtod(str, NULL));
	this->_Cchar = static_cast<char>(this->_Cdouble);
	this->_Cint = static_cast<long>(this->_Cdouble);
	this->_Cfloat = static_cast<float>(this->_Cdouble);
}

unsigned char	Convert::getChar() const {
	return this->_Cchar;
}

long			Convert::getInt() const {
	return this->_Cint;
}

float			Convert::getFloat() const {
	return this->_Cfloat;
}

double			Convert::getDouble() const {
	return this->_Cdouble;
}

bool			Convert::getInvalid() const {
	return this->_Cinvalid;
}

bool			Convert::getPseudo() const {
	return this->_Cpseudo;
}

std::ostream	&Convert::handlePseudo(std::ostream &o, Convert const &c) {
	o << "char: impossible\nint: impossible\nfloat: ";
	std::string str = c.getStr();
	char		first_char = str[0];
	if (first_char == '-' || first_char == '+') {
		o << first_char;
		str = str.substr(1, str.length() - 1);
	}
	o << str.substr(0, 3) << "f\ndouble: ";
	if (first_char == '-' || first_char == '+') {
		o << first_char;
	}
	o << str.substr(0, 3) << std::endl;
	return o;
}

std::ostream	&operator<<(std::ostream &o, Convert const &c) {
	if (c.getInvalid()) {
		o << c.getStr() << " isn't a valid value to convert" << std::endl;
		return o;
	}
	if (c.getPseudo()) { return ((Convert)c).handlePseudo(o, c); }
	char Cchar[11];
	Cchar[0] = c.getChar();
	Cchar[1] = 0;
	Cchar[10] = 0;
	if (!isprint(Cchar[0])) {
		strcpy(Cchar, "impossible");
	}
	float Cfloat = c.getFloat();

	o << "char: " << Cchar << "\n" <<
		"int: " << c.getInt() << "\n" << "float: ";
		if (Cfloat - static_cast<int>(Cfloat) == 0) {
			o.precision(1); std::cout << std::fixed;
		}
		o << Cfloat << "f" << "\n" <<
		"double: " << c.getDouble() << std::endl;
	return o;
}