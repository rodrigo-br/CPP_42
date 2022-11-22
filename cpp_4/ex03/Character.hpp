#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

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
		std::string const	&getName();
		void				equip(AMateria* m);
		void				use(int idx, ICharacter& target);
};

#endif