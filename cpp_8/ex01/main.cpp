#include "Span.hpp"

int main (void)
{
	Span sp = Span(5);

	try {
		sp.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	for (int i=0; i<5; i++) {
		sp.addNumber(i);
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(5);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	sp1.showStorage();
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	std::set<int> manyTest;
	for (int i = 0; i < 10001; i++) {
		manyTest.insert(i);
	}
	Span sp2 = Span(10001);
	sp2.addMany(manyTest.begin(), manyTest.end());
	std::cout << sp2.longestSpan() << "\n";
	//std::cout << sp2.shortestSpan() << "\n"; it can take a while
}