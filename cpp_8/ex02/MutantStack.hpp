#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	private:


	public:

		MutantStack() {};
		~MutantStack() {};

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

};

#endif
