#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:

		Cure();
		Cure(Cure const &src);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};


#endif