#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <algorithm>
#include <set>

class Span
{
	private:

		std::set<int>	_storage;
		unsigned int	_capacity;
		Span();

	public:

		Span(unsigned int n);
		~Span();

		void			addNumber(int n);
		void			addMany(std::set<int>::iterator first, std::set<int>::iterator last);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		unsigned int	compare(int distance) const;
		void			showStorage() const;

		class storageFullException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class notEnoughToCompareException : public std::exception
		{
			virtual const char *what() const throw();
		};

};


#endif