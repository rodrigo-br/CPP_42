#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:

		Ice();
		Ice(Ice const &src);
		~Ice();

		Ice* clone() const;
		//void use(ICharacter& target);
};


#endif