#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain			*brain;

	protected:
		std::string		type;
		
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

	Cat	&operator=(Cat const &src);

	void			makeSound() const;
	std::string		getType() 	const;
	Brain			*getBrain()	const;
};

std::ostream	&operator<<(std::ostream &o, Cat const &value);

#endif