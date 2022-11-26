#include "Base.hpp"

int main(void)
{
	Base *random_derivated_pointer = generate();
	identify(random_derivated_pointer);
	
	Base &random_derivated_reference = *random_derivated_pointer;
	identify(random_derivated_reference);

	delete random_derivated_pointer;
}
