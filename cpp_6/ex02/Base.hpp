#ifndef BASE_H
# define BASE_H

#include <cstdlib>
#include <time.h>
#include <iostream>

class A;
class B;
class C;
class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif