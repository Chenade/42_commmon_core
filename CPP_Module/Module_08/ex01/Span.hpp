# ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

class Span
{
	private:
		unsigned int	_n;
		std::list<int>  _list;
		Span();
	
	public:
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		Span& operator=(const Span& span);

		unsigned int	getN() const;

		void	print();
		void	addNumber(int value);
		int	longestSpan();
		int	shortestSpan();
};

#endif