#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_known_materials[4];
		int			_nOfKnownMaterials;
		
	public:
		MateriaSource(MateriaSource const &src);
		MateriaSource();
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &src);

		void		learnMateria(AMateria *materia);
		AMateria*	createMateria(std::string const &type);
};

#endif