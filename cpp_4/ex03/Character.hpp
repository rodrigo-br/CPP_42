#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define INVENTORY_SIZE 4

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[INVENTORY_SIZE];
		int				_nOfMaterials;

	public:

		Character(std::string name);
		Character();
		~Character();
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		AMateria*			getMateriaFromFloor();
		AMateria*			getMateriaFromFloor(int idx);

		static int			materialsOnFloor;
		static AMateria		*floor[10];
};

#endif