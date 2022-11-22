#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	private:
		AMateria();

	protected:

		std::string			_type;

	public:

		AMateria(std::string const &type);
		virtual ~AMateria();
		std::string			const	&getType() const;
		virtual AMateria* 			clone() const = 0;
		virtual void				use(ICharacter& target);
};

#endif