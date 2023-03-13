#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int size) : _n(size)
{
}

Span::Span(const Span& src) : _n(src._n)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& rhs)
{
    if ( this != &rhs )
        _n = rhs.getN();
    return *this;
}

unsigned int Span::getN() const
{
   return (_n);
}

void	Span::print()
{
    std::cout << "The list is: ";
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void	Span::addNumber(int value)
{
	if (_list.size() >= _n)
		throw std::out_of_range("Span::addNumber: list is full");
	_list.push_back(value);
}

int	Span::longestSpan()
{
	if (_list.size() < 2)
		throw std::out_of_range("Error: list is empty or only one element");
	std::list<int>::iterator max = std::max_element( _list.begin(), _list.end());
	std::list<int>::iterator min = std::min_element( _list.begin(), _list.end());
	return (*max - *min);
}

int	Span::shortestSpan()
{
	if (_list.size() < 2)
		throw std::out_of_range("Error: list is empty or only one element");
	
	int shortest = Span::longestSpan();
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	{
		for (std::list<int>::iterator jt = it; jt != _list.end(); ++jt)
		{
			if (abs(*jt - *it) < shortest && jt != it)
				shortest = abs(*jt - *it);
		}
	}
	return (shortest);
}
